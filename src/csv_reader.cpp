#include "csv_reader.hpp"
#include <string>
#include <vector>
#include <iostream>

void dataFrame::read_from_csv(std::istream &istr, size_t y_pos) {
    if (!istr) {
        std::cerr << "File is closed" << std::endl;
    }

    std::string line;

    {
        if (!getline(istr, line)) {
            std::cerr << "Invalid .csv" << std::endl;
            std::cout << line;
        }
        // ignore colnames
//        std::istringstream sstream(line);
//        while (sstream.getline(name, 256, ',')) {
//
//        }
    }

    while (getline(istr, line)) {
        std::istringstream sstream(line);
        std::vector<double> csv_line;

        std::string entry;
        size_t colname = 0;
        while (getline(sstream, entry, ',')) {
            if (colname > 0) {
                try {
                    if (colname != y_pos) {
                        csv_line.push_back(std::stod(entry));
                    } else {
                        y.push_back(std::stod(entry));
                    }
                } catch (...) {
                    std::cerr << "Invalid symbol in .csv file : " << entry << std::endl;
                }
            }
            ++colname;
        }

        X.push_back(csv_line);
    }
}

const std::vector<std::vector<double>> &dataFrame::get_X() const {
    return X;
}

const std::vector<double> &dataFrame::get_y() const {
    return y;
};
