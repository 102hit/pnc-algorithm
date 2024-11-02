
#include <iostream>
#include <tuple>
using namespace std;
// 定义二维点结构体
struct Point {
    double x, y;
};

// 计算向量叉积
double crossProduct(const Point& A, const Point& B, const Point& C) {
    return (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
}


bool checkIntersect(const Point& A, const Point& B, const Point& C, const Point& D){
    auto cross_product = [](const Point& X, const Point& Y, const Point& Z)-> double {
        return (Y.x - X.x) * (Z.y - X.y) - (Z.x - X.x) * (Y.y - X.y);
    };
    return (cross_product(A, B, C) * cross_product(A, B, D) <= 0) && (cross_product(C, D, A) * cross_product(C, D, B) <= 0);
}
// 测试代码
int main() {
    Point A = {0, 0};
    Point B = {4, 4};
    Point C = {0, 0.04};
    Point D = {4, 0};
    // if (doIntersect(A, B, C, D)) {
    if (checkIntersect(A, B, C, D)) {
        std::cout << "线段相交" << std::endl;
    } else {
        std::cout << "线段不相交" << std::endl;
    }
    return 0;
}
