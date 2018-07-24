//
// Created by 赵绪言 on 2018/7/24.
//

#include "../header/Utils.h"

CUtils::CUtils() = default;

CUtils::~CUtils() = default;

string CUtils::int2string(int n) {
    string res;
    stringstream ss;
    ss << n;
    ss >> res;
    return res;
}
