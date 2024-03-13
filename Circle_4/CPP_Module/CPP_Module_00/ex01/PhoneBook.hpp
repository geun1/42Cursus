/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:57:44 by gsong             #+#    #+#             */
/*   Updated: 2023/08/14 16:09:09 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H_
# define PHONEBOOK_H_

#include "Contact.hpp"
#include <string>

class PhoneBook {
    private:
        Contact contact[8];
        Contact CreateContact();
        void DisplaySearchList(std::string contactInfo);
        void DisplayContact();
        void ValidateInputIndex(std::string inputIndex);
        int idx;

    public:
        PhoneBook();
        ~PhoneBook();
        void AddContact();
        void SearchContact();
};

#endif
