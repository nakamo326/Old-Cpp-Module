#include "contact.hpp"

const std::string Contact::q_list[Contact::q_num] = {"first name",
                                                     "last name",
                                                     "nickname",
                                                     "login",
                                                     "postal address",
                                                     "email address",
                                                     "phone number",
                                                     "birthday date",
                                                     "favorite meal",
                                                     "underwear color",
                                                     "darkest secret"};

void Contact::set_info(int index, std::string &str) {
  this->info[index] = str;
}

const std::string &Contact::get_info(int index) {
  return this->info[index];
}
