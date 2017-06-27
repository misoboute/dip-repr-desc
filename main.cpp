#include <iostream>
#include <string>
#include <curses.h>

#include <sstream>
//#include <thread>
//#include "../Enhanced-Elastography/EnhancedElastography/PDebug.h"

using namespace std;

std::string normalize_chain_starting_point(const std::string& chain) {
    auto len = chain.size();
    auto normal = chain;
    for (int i = 1; i < len; ++i) {
        auto alternative = chain.substr(i) + chain.substr(0, i);
        if (alternative < normal)
            normal = alternative;
    }
    return normal;
}

std::string compute_first_difference(const std::string& chain, int directions) {
    auto len = chain.size();
    ostringstream diffChain;
    for (int i = 0; i < len - 1; ++i) {
        diffChain << (chain[i + 1] - chain[i] + directions) % directions;
    }
    return diffChain.str();
}

class main_window {
public:

    main_window(int lines, int columns, int x0, int y0) {
        initscr();
        cbreak();
        window_ = newwin(lines, columns, y0, x0);
        refresh();
    }

    void run_menu() {
        while (true) {
            wclear(window_);
            waddstr(window_, "This is a demonstration of the solution to the problems at the end of chapter 11 of the book Digital "
                    "Image Processing by author Gonzalez. Select a problem from the list below:\n\n");
            waddstr(window_, "1: Problem 11.1\n");
            waddstr(window_, "2: Problem 11.2\n");
            waddstr(window_, "3: Problem 11.3\n");
            waddstr(window_, "4: Problem 11.4\n");
            waddstr(window_, "5: Problem 11.5\n");
            waddstr(window_, "q: Quit the program\n");
            wrefresh(window_);
        noecho();
            auto inputCh = getch();
            if (inputCh == 'q' || inputCh == 'Q')
                break;
            if (inputCh == '1')
                problem_11_1();
            if (inputCh == '2')
                problem_11_2();
            if (inputCh == '3')
                problem_11_3();
            if (inputCh == '4')
                problem_11_4();
            if (inputCh == '5')
                problem_11_5();
        }
    }

    void problem_11_1() {
        wclear(window_);
        waddstr(window_, "Enter the chain for starting point normalization (hit enter for default = 11076765543322): ");
        char chain[max_str];
        echo();
        wgetnstr(window_, chain, max_str);
        std::string chainStr = *chain == 0 ? "11076765543322" : chain;
        waddstr(window_, "Normalized chain: ");
        waddstr(window_, normalize_chain_starting_point(chainStr).c_str());
        waddstr(window_, "\nPress any key to go back to main menu...");
        noecho();
        wrefresh(window_);
        getch();
    }

    void problem_11_2() {
        wclear(window_);
        waddstr(window_, "Enter the chain for rotation normalization (hit enter for default = 0101030303323232212111): ");
        char chain[max_str];
        echo();
        wgetnstr(window_, chain, max_str);
        std::string chainStr = *chain == 0 ? "0101030303323232212111" : chain;
        waddstr(window_, "Is the chain 4- or 8-coded (default = 4): ");
        wrefresh(window_);
        noecho();
        int coding = getch() == '8' ? 8 : 4;
        waddstr(window_, "\nNormalized chain: ");
        waddstr(window_, compute_first_difference(chainStr, coding).c_str());
        waddstr(window_, "\nPress any key to go back to main menu...");
        wrefresh(window_);
        getch();
    }

    void problem_11_3() {
        wclear(window_);
        waddstr(window_, "Not implemented yet!");
        waddstr(window_, "\nPress any key to go back to main menu...");
        wrefresh(window_);
        getch();
    }

    void problem_11_4() {
        wclear(window_);
        waddstr(window_, "Not implemented yet!");
        waddstr(window_, "\nPress any key to go back to main menu...");
        wrefresh(window_);
        getch();
    }

    void problem_11_5() {
        wclear(window_);
        waddstr(window_, "Not implemented yet!");
        waddstr(window_, "\nPress any key to go back to main menu...");
        wrefresh(window_);
        getch();
    }

    ~main_window() {
        delwin(window_);
        endwin();
    }

private:
    WINDOW* window_;
    const int max_str = 256;
};

int main(int argc, char ** argv) {
    initscr();
    auto menuWin = main_window(10, COLS - 10, 5, 2);
    menuWin.run_menu();
    return 0;
}
