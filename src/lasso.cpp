#include "lasso.hpp"
#include <iostream>
//#include <cassert>

namespace {

    std::vector<double> mul_mat_vec(
            const std::vector<std::vector<double>> &mat,
            const std::vector<double> &vec
    ) {
        std::vector<double> result(mat.size(), 0);
        for (size_t i = 0; i < mat.size(); ++i) {
            for (size_t j = 0; j < vec.size(); ++j) {
                result[i] += mat[i][j] * vec[j];
            }
        }
        return result;
    }

}


void lasso(
        const std::vector<std::vector<double>> &X,
        const std::vector<double> &y,
        std::vector<double> &w,
        double lambda,
        double eps,
        size_t max_iter
) {
    std::vector<double> z(X[0].size(), 0);
    for (size_t i = 0; i < X.size(); ++i) {
        for (size_t j = 0; j < X[0].size(); ++j) {
            z[j] += X[i][j] * X[i][j];
        }
    }

    size_t iter = 0;
    while (iter++ < max_iter) {

        double maxdiff = 0;
        for (size_t j = 0; j < X[0].size(); ++j) {

            double prev_w = w[j];
            w[j] = 0;

            std::vector<double> rss = mul_mat_vec(X, w);
            for (size_t i = 0; i < rss.size(); ++i) {
                rss[i] = y[i] - rss[i];
            }

            double rho = 0;
            for (size_t i = 0; i < X.size(); ++i) {
                rho += X[i][j] * rss[i];
            }

            if (2 * rho < -lambda) {
                w[j] = (rho + lambda / 2) / z[j];
            } else if (2 * rho > lambda) {
                w[j] = (rho - lambda / 2) / z[j];
            } else {
                w[j] = 0;
            }

            maxdiff = std::max(maxdiff, std::abs(w[j] - prev_w));
        }

        if (maxdiff < eps) {
            break;
        }
    }
}


//void sparse01_lasso(
//        const std::vector<std::vector<size_t>> &X,
//        size_t num_features,
//        const std::vector<double> &y,
//        std::vector<double> w,
//        double lambda,
//        double eps,
//        size_t max_iter
//) {
//    std::vector<double> z(num_features, 0);
//    for (size_t i = 0; i < X.size(); ++i) {
//        for (size_t idx : X[i]) {
//            z[idx] += 1;
//        }
//    }
//
//    size_t iter = 0;
//    while (iter++ < max_iter) {
//
//        double maxdiff = 0;
//        for (size_t j = 0; j < num_features; ++j) {
//
//            double prev_w = w[j];
//            w[j] = 0;
//
//            std::vector<double> rss = y;
//            for (size_t i = 0; i < rss.size(); ++i) {
//                for (size_t idx: X[i]) {
//                    rss[i] -= w[idx];
//                }
//            }
//
//            double rho = 0;
////            for (size_t i = 0; i < X.size(); ++i) {
////                rho += X[i][j] * rss[i];
////            }
//
//            if (2 * rho < -lambda) {
//                w[j] = (rho + lambda / 2) / z[j];
//            } else if (2 * rho > lambda) {
//                w[j] = (rho - lambda / 2) / z[j];
//            } else {
//                w[j] = 0;
//            }
//
//            maxdiff = std::max(maxdiff, std::abs(w[j] - prev_w));
//        }
//
//        if (maxdiff < eps) {
//            break;
//        }
//    }
//}