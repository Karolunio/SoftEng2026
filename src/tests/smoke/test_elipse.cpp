#include <gtest/gtest.h>
#include <cmath>
#include <limits>

#include "Ellipse.h"
#include "ShapeParam.h"
#include "ShapeResultData.h"

TEST(EllipseTest, HappyPathStandard)
{
    ShapeParam<double> param;
    param.set_attrib(ShapeParamIndex::PARAM_RADIUS, 5.0);
    param.set_attrib(ShapeParamIndex::PARAM_RADIUS_2, 3.0);
    
    Ellipse<double> ellipse(param);
    ShapeResult<double> result = ellipse.compute();

    double expectedArea = 3.141592653589 * 5.0 * 3.0;

    EXPECT_NEAR(result.get_attrib(ShapeResultIndex::RESULT_AREA), expectedArea, 1e-4);
}

TEST(EllipseTest, BoundaryZero)
{
    ShapeParam<double> param;
    param.set_attrib(ShapeParamIndex::PARAM_RADIUS, 0.0);
    param.set_attrib(ShapeParamIndex::PARAM_RADIUS_2, 10.0);
    
    Ellipse<double> ellipse(param);
    ShapeResult<double> result = ellipse.compute();

    EXPECT_DOUBLE_EQ(result.get_attrib(ShapeResultIndex::RESULT_AREA), 0.0);
}

TEST(EllipseTest, BoundaryMax)
{
    ShapeParam<float> param;
    param.set_attrib(ShapeParamIndex::PARAM_RADIUS, std::numeric_limits<float>::max());
    param.set_attrib(ShapeParamIndex::PARAM_RADIUS_2, std::numeric_limits<float>::max());
    
    Ellipse<float> ellipse(param);
    ShapeResult<float> result = ellipse.compute();

    EXPECT_TRUE(std::isinf(result.get_attrib(ShapeResultIndex::RESULT_AREA)));
}

TEST(EllipseTest, GeometricLogicCircle)
{
    ShapeParam<double> param;
    param.set_attrib(ShapeParamIndex::PARAM_RADIUS, 10.0);
    param.set_attrib(ShapeParamIndex::PARAM_RADIUS_2, 10.0);
    
    Ellipse<double> ellipse(param);
    ShapeResult<double> result = ellipse.compute();

    double expectedArea = 3.141592653589 * 100.0;
    EXPECT_NEAR(result.get_attrib(ShapeResultIndex::RESULT_AREA), expectedArea, 1e-4);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}