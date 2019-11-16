#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <sstream>

class dataFrame {
public:
    dataFrame() = default;

    void read_from_csv(std::istream &istr, size_t y_pos);

    [[nodiscard]] const std::vector<std::vector<double>> &get_X() const;

    [[nodiscard]] const std::vector<double> &get_y() const;

private:
    std::vector<std::vector<double>> X;
    std::vector<double> y;
};