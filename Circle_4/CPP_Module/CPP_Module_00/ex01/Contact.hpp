/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:45:13 by gsong             #+#    #+#             */
/*   Updated: 2023/08/14 16:09:15 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H_
# define CONTACT_H_

#include <iostream>

class Contact {
    private: //클래스 내부에서만 접근 가능한 요소, 클래스로 접근해야만 쓸 수 있음
        // 멤버변수: 클래스 안에 있는 변수
        std::string firstName; //std는 namespace 임 iostream에 있음
        std::string lastName;
        std::string nickName;
        std::string phoneNumber;
        std::string darkestSecret;

    public: // 클래스 외부에서도 접근 가능한 요소
        Contact(); //생성자 constructor
        ~Contact(); //소멸자 destructor
        Contact(
            std::string firstName,
            std::string lastName,
            std::string nickName,
            std::string phoneNumber,
            std::string darkestSecret
        );
        std::string GetFirstName();
        std::string GetLastName();
        std::string GetNickName();
        std::string GetPhoneNumber();
        std::string GetDarkestSecret();
};

// 클래스의 구성요소
// 1. 멤버 변수 : 클래스 안에 있는 변수 -> 보통 private 접근 지정자 사용

// 2. 생성자 : 보통 public에 명시, 객체등록, 필드 초기화 등의 역할, 객체 생성시 자동 호출, 오버로딩 가능
// 3. 멤버 함수
// 4. 복사 생성자
// 5. 소멸자
// 6. 대입연산자 함수

#endif

