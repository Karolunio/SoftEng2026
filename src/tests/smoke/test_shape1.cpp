
#define _USE_MATH_DEFINES
#include <cmath>
#include <gtest/gtest.h>
#include "ShapeFactory.h"

TEST(test_shape1, AddFunction)
{
    bool res=true;
    ShapeParam<float> param;
    res = param.set(ShapeParamIndex::PARAM_RADIUS, 1.f);
    ASSERT_NE(res, false);

    param.type=ShapeType::PT_CIRCLE;

    res = param.validate();
    ASSERT_NE(res, false);

    auto shape = std::unique_ptr<IShape<float>>(ShapeFactory<float>::create(param));
    ASSERT_NE(shape, nullptr);

    ShapeResultData<float> data=shape->compute();
    float area=data.get(ShapeResultIndex::RESULT_AREA);
    ASSERT_NE(area, 0.f);

    shape.reset(nullptr);

    ASSERT_EQ(shape.get(), nullptr);
}


int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

    // TST
    /*ShapeParam<double> param;

    param.set(PARAM_RADIUS, 5.0);
    param.set(PARAM_RADIUS_2, 2.0);

    Torus<double> torus(param);

    ShapeResultData<double> result = torus.compute();

    cout << torus.print() << endl;
    cout << "Volume: " << result.get(RESULT_VOLUME) << endl;
    cout << "Surface: " << result.get(RESULT_SURFACE) << endl;

    return 0;*/
}