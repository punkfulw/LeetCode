#include <iostream>
#include <math.h>
using namespace std;
#define ABS_FLOAT_0 0.0001
struct point_float
{
float x;
float y;
};
/**

* @brief 计算三角形面积

*/

float GetTriangleSquar(const point_float pt0, const point_float pt1, const point_float pt2)
{
    point_float AB,   BC;
    AB.x = pt1.x - pt0.x;
    AB.y = pt1.y - pt0.y;
    BC.x = pt2.x - pt1.x;
    BC.y = pt2.y - pt1.y;
    return fabs((AB.x * BC.y - AB.y * BC.x)) / 2.0f;
}
/**

* @brief 判断给定一点是否在三角形内或边上

*/
bool IsInTriangle(const point_float A, const point_float B, const point_float C, const point_float D)
{
    float SABC, SADB, SBDC, SADC;
    SABC = GetTriangleSquar(A, B, C);
    SADB = GetTriangleSquar(A, D, B);
    SBDC = GetTriangleSquar(B, D, C);
    SADC = GetTriangleSquar(A, D, C);
    float SumSuqar = SADB + SBDC + SADC;
    if ((-ABS_FLOAT_0 < (SABC - SumSuqar)) && ((SABC - SumSuqar) < 
        ABS_FLOAT_0))
    {
        return true;
    }
    else
    {
        return false;
    }
}
