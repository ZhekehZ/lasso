#pragma once

#include <vector>
#include <functional>


void lasso(
        const std::vector<std::vector<double>> &X,
        const std::vector<double> &y,
        std::vector<double> &w,
        double lambda,
        double eps,
        size_t max_iter
);

//void sparse01_lasso(
//        const std::vector<std::vector<size_t>> &X,
//        size_t num_features,
//        const std::vector<double> &y,
//        std::vector<double> w,
//        double lambda,
//        double eps,
//        size_t max_iter
//);


