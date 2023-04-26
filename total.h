#ifndef TOTAL_H
#define TOTAL_H

#define MAX_BUF 4096
#define ADMINISTRATOR_MODE 2
#define READER_MODE 3



struct books 
{
    char *book_name;
    char *author;
    char *translator;
    char *publisher;
    int publish_year;
    int amount;
    float call_number;
    char *isbn;
    int viewer_count;
    int accession_number;
    char *borrower;
    int expiry_date[MAX_BUF];

};

struct administrators
{
    char *ad_name;
    char *ad_account;
    char *ad_password;
};

struct readers
{
    char *re_name;
    int student_id[MAX_BUF];
    char *grade;
    char *email;
    char *re_account;
    char *re_password;
    char *borrow_history;
    int credit;
    struct readers *next;
    struct readers *prev;
    struct readers *link;
};

void interface_choose_identity(int mode); //mode

void interface_ad_entry(int option_entry);

void interface_re_entry(int option_entry);

void set_reader(struct readers **list);

void check_account_ad(char account[]);

void check_password_ad(char password[]);

void check_account_re(char account[]);

void check_password_re(char password[]);

void sign_in_administrator(char account[], char password[]);

void sign_in_reader();

/* Administrator mode */
void administrator_mode();

void interface_ad();

void review_library();

void add_book();

void delete_book();

void check_borrowing();

void check_re_information();

void check_ad_information();

void set_administrator();

void lend_book();

/* Reader mode*/
void reader_mode();

void interface_re();

void check_personal_information();

void search_book_name();

void search_author();

void search_publisher();

void search_call_number();

void search_isbn();

void search_viewer_count();

void show_book();

#endif /* TOTAL_H */