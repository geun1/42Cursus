import Component from "../core/Component.js";
import DetailInfo from"../components/DetailInfo.js";
import api from "../api/http.js";

export default class SearchUser extends Component {
  setup() {
    this.$state = {
      user_profiles: [
        // {
        //   intra_pk_id: '1',
        //   intra_id: 'seunghwk',
        //   nick_name: 'seunghwk',
        //   is_login: true,
        //   is_friend: false
        // },
        // {
        //   intra_pk_id: '1',
        //   intra_id: 'gsong',
        //   is_login: false,
        //   is_friend: true
        // },
      ],
    };
  }

  template() {
    return `
    <div id ="searchBox">
      <div id = "searchInputBox">
        <input type="text" class="searchInput" id="searchInput"  value="" placeholder="intraID">
        <button id ="searchButton"  class="searchButton"><img id="searchButtonIcon" src="../../assets/searchIcon.png"></img></button>
      </div>
      <div id="searchResultBox">
         ${this.$state.user_profiles.map(user => `
        <div id ="searchResultItem">
          <div id="searchResultItemIntraId"> ${user.intra_id} ${user.is_login === true ?'<div id="isLoginTrueCircle"></div>':'<div id="isLoginFalseCircle"></div>'}</div>
          <button class="btn btn-primary" id="detailInfoButton" data-user-id="${user.intra_pk_id}">상세 정보</button>
          ${user.is_friend === true ?
          '<p id ="searchResultP" class="btn btn-primary">친구</p>' : `<button class="btn btn-primary" id="addButton" data-user-id="${user.intra_pk_id}">친구 추가</button>`}
          </div>
          <hr>
      `).join('')}
      </div>
      <div id="modalContainer">
        <div id="modal">
          <span id="modalClose">&times;</span>
          <div data-component='detailInfo' id="detailInfo"/>
        </div>
      </div>
    </div>
    `;
  }

  setEvent() {
    this.addEvent('click', '.searchButton', () => this.handleSearchButtonClick());
    this.addEvent('click', '#detailInfoButton', (e) => this.handleDetailInfoButtonClick(e));
    this.addEvent('click', '#addButton', (e) => this.handleAddButtonClick(e));
    this.addEvent('click', '#modalClose', () => this.handleModalCloseButtonClick());
  }

  handleSearchButtonClick() {
    const searchInput = this.$target.querySelector('.searchInput');
    const searchValue = searchInput.value;

    this.searchUser(searchValue);
  }

  handleDetailInfoButtonClick(e) {
    const $detailInfo = this.$target.querySelector(
      "[data-component='detailInfo']"
    );
    const targetUserId = e.target.dataset.userId;

    new DetailInfo($detailInfo, { id: targetUserId });

    const modalContainer = document.getElementById('modalContainer');
    modalContainer.style.display = 'flex';
    modalContainer.focus();
  }

  handleModalCloseButtonClick() {
    const modalContainer = document.getElementById('modalContainer');
    modalContainer.style.display = 'none';
  }

  handleAddButtonClick(e) {
    const targetUserId = e.target.dataset.userId;
    const targetUser = this.$state.user_profiles.find(user => user.intra_pk_id === targetUserId);
    const updatedUser = { ...targetUser, is_friend: true };
    const newState = {
      ...this.$state,
      user_profiles: this.$state.user_profiles.map(user => (user.intra_pk_id === targetUserId ? updatedUser : user)),
    };

    // 아래 함수에서 요청이 잘 처리되었을 때 함수 내에서 setState 호출 예정
    this.addFriend(targetUserId);
    this.setState(newState);
  }

  async searchUser(searchValue) {
    const path = `/users/info/search?key_word=${searchValue}`;
    const token = localStorage.getItem('token');
    const headers = { 'JWT': token };

    try {
      const response = await api.get(path, headers);

      this.setState({
        user_profiles: response.user_profiles,
      });
      console.log(response);
    } catch (error) {
      console.error('Error fetching data:', error);
    }
  }

  async addFriend(targetUserId) {
    const path = `/friends/add?friend_intra_pk_id=${targetUserId}`;
    const token = localStorage.getItem('token');
    const headers = { 'JWT': token };
    try {
      const response = await api.post(path,{}, headers);
    } catch (error) {
      console.error('Error fetching data:', error);
    }
  }
}
