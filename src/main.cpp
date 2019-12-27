#include <iostream>
#include <iomanip>

using namespace std;

// Current State of the prompt acii format
// m (109) = Main Menu
// c  (99) = Categories Menu
// 4 (114) = Repos Menu
// s (115) = SubCategories List
char state = 109;

template<typename T> void printElement(T t, const int& width)
{
    const char separator    = '    ';
    cout << left << setw(width) << setfill(separator) << t;
}


void show_logo() {
    char * logo = "\n"
                  "\n"
                  "$$\\   $$\\           $$\\                         $$\\ $$\\           \n"
                  "$$ | $$  |          $$ |                        $$ |\\__|          \n"
                  "$$ |$$  / $$$$$$\\ $$$$$$\\    $$$$$$\\   $$$$$$\\  $$ |$$\\ $$$$$$$\\  \n"
                  "$$$$$  /  \\____$$\\\\_$$  _|  $$  __$$\\ $$  __$$\\ $$ |$$ |$$  __$$\\ \n"
                  "$$  $$<   $$$$$$$ | $$ |    $$ /  $$ |$$ /  $$ |$$ |$$ |$$ |  $$ |\n"
                  "$$ |\\$$\\ $$  __$$ | $$ |$$\\ $$ |  $$ |$$ |  $$ |$$ |$$ |$$ |  $$ |\n"
                  "$$ | \\$$\\\\$$$$$$$ | \\$$$$  |\\$$$$$$  |\\$$$$$$  |$$ |$$ |$$ |  $$ |\n"
                  "\\__|  \\__|\\_______|  \\____/  \\______/  \\______/ \\__|\\__|\\__|  \\__|\n"
                  "                                                                  \n"
                  "                                                                  \n"
                  "                                                                  \n"
                  "                                   $$$$$$\\                        \n"
                  "                                  $$ ___$$\\                       \n"
                  "                        $$\\    $$\\\\_/   $$ |                      \n"
                  "                        \\$$\\  $$  | $$$$$ /                       \n"
                  "                         \\$$\\$$  /  \\___$$\\                       \n"
                  "                          \\$$$  / $$\\   $$ |                      \n"
                  "                           \\$  /  \\$$$$$$  |                      \n"
                  "                            \\_/    \\______/                       \n"
                  "                                                                  \n"
                  "";
    std::cout << logo << std::endl;
}
void show_main_menu(void) {
    state = 109;
    system("clear");
    show_logo();

    cout << endl;
    printElement("1) Add Kali Respositories & Update", 40);
    cout << endl;
    printElement("2) View Categories", 40);
    cout << endl;
    printElement("3) Help", 40);
    cout << "\n" << endl;
}

void show_add_repos() {
    state = 114;
    system("clear");
    show_logo();

    printElement("1) Add Kali Repositories", 40);
    cout << endl;
    printElement("2) Update", 40);
    cout << endl;
    printElement("3) Remove all kali linux repositories", 40);
    cout << endl;
    printElement("4) View Contents of sources.list", 40);
    cout << "\n" << endl;
    printElement("99) Go Home", 40);
    cout << "\n" << endl;
}

void show_categories(void) {
    state = 99;
    system("clear");
    show_logo();

    cout << "Categories:" << endl;
    printElement("1) Information Gathering", 30);
    printElement("8) Exploitation Tools", 30);
    cout << endl;
    printElement("2) Vulnerability Analysis", 30);
    printElement("9) Forensics Tools", 30);
    cout << endl;
    printElement("3) Wireless Attacks", 30);
    printElement("10) Stress Testing", 30);
    cout << endl;
    printElement("4) Web Applications", 30);
    printElement("11) Password Attacks", 30);
    cout << endl;
    printElement("5) Sniffing & Spoofing", 30);
    printElement("12) Reverse Engineering", 30);
    cout << endl;
    printElement("6) Maintaining Access", 30);
    printElement("13) Hardware Hacking", 30);
    cout << endl;
    printElement("7) Reporting Tools", 30);
    printElement("14) Extra", 30);
    cout << endl;
    cout << "\n" << endl;
    printElement("0) All", 30);
    cout << "\n" << endl;
    printElement("99) Go Back", 30);
    cout << "\n" << endl;
}

void do_correct_thing(int selection) {
    if (state == 109) { // Main Menu
        switch (selection) {
            case 1:
                show_add_repos();
                break;
            case 2:
                show_categories();
                break;
            default:
                cout << "Invalid Option\n" << endl;
                break;
        }
    } else if (state == 99) { // Categories Menu
        switch(selection) {
            case 99:
                show_main_menu();
                break;
            default:
                cout << "Invalid Option\n" << endl;
                break;
        }
    } else if (state == 114) { // Repos Menu
        switch(selection) {
            case 99:
                show_main_menu();
                break;
            default:
                cout << "Invalid Option\n" << endl;
                break;
        }
    }
}




int main() {
    char state = 109;
    show_main_menu();

    int selected_option = NULL;
    for (;;) {
        cout << "kat> ";
        cin >> selected_option;
        do_correct_thing(selected_option);
    }
    return 0;
}

