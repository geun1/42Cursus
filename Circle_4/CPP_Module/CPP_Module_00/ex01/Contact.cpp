/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:57:25 by gsong             #+#    #+#             */
/*   Updated: 2023/08/14 16:09:17 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(
    std::string firstName,
    std::string lastName,
    std::string  nickName,
    std::string phoneNumber,
    std::string darkestSecret
) {
    this->firstName = firstName;
    this->lastName = lastName;
    this->nickName= nickName;
    this->phoneNumber = phoneNumber;
    this->darkestSecret = darkestSecret;
}

Contact::Contact() {
    *this = Contact("", "", "", "", "");
}

Contact::~Contact() {
}

std::string Contact::GetFirstName() {
    return this->firstName;
}

std::string Contact::GetLastName() {
    return this->lastName;
}

std::string Contact::GetNickName() {
    return this->nickName;
}

std::string Contact::GetPhoneNumber() {
    return this->phoneNumber;
}

std::string Contact::GetDarkestSecret() {
    return this->darkestSecret;
}
