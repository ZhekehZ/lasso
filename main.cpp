#include "src/csv_reader.hpp"
#include "src/lasso.hpp"
#include <iostream>
#include <fstream>
#include <random>
#include <iomanip>

void test_lasso() {
    dataFrame df;
    std::ifstream fin("../Boston.csv");
    df.read_from_csv(fin, 14);

    std::vector<double> w(df.get_X()[0].size(), 0);

    std::default_random_engine gen;
    std::normal_distribution<double> rand(0, 1);
    for (auto &a : w) {
        a = rand(gen);
    }

    std::cout << std::setw(10) << "INIT W = ";
    for (auto a : w) {
        std::cout << std::setw(10) << a << '\t';
    }
    std::cout << '\n';

    lasso(df.get_X(), df.get_y(), w, 50000.0, 0.3, 100);

    std::cout << std::setw(10) << "LASSO W = ";
    for (auto a : w) {
        std::cout << std::setw(10) << a << '\t';
    }
    std::cout << '\n';
}


//void test_sparse01_lasso() {
//    size_t num_features = 15;
//    size_t num_elements = 1500;
//    std::vector<std::vector<size_t>> X;
//    std::vector<double> y;
//
//    std::default_random_engine gen;
//    std::uniform_int_distribution<size_t> rand(0, num_features - 1);
//    std::normal_distribution<double> rand_d(0, 1);
//
//    for (size_t i = 0; i < num_elements; ++i) {
//        std::vector<size_t> idxes;
//        size_t num = rand(gen);
//        for (size_t j = 0; j < num; ++j) {
//            idxes.push_back(rand(gen));
//        }
//        y.push_back(idxes.size());
//        X.push_back(idxes);
//    }
//
//    std::vector<double> w(num_features);
//    for (auto &a : w) {
//        a = rand_d(gen);
//    }
//
//    std::cout << std::setw(10) << "INIT W = ";
//    for (auto a : w) {
//        std::cout << std::setw(10) << a << '\t';
//    }
//    std::cout << '\n';
//
//    sparse01_lasso(X, num_features, y, w, 1000.0, 100.0, 10000);
//
//    std::cout << std::setw(10) << "LASSO W = ";
//    for (auto a : w) {
//        std::cout << std::setw(10) << a << '\t';
//    }
//    std::cout << '\n';
//}


int main() {
    test_lasso();

    //test_sparse01_lasso();

    return 0;
}