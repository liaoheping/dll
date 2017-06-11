//=======================================================================
// Copyright (c) 2014-2017 Baptiste Wicht
// Distributed under the terms of the MIT License.
// (See accompanying file LICENSE or copy at
//  http://opensource.org/licenses/MIT)
//=======================================================================

#pragma once

namespace dll {

/*!
 * \brief Descriptor for a 2D pooling layer desc
 */
template <size_t T_I1, size_t T_I2, size_t T_I3, size_t T_C1, size_t T_C2, typename... Parameters>
struct pooling_layer_2d_desc {
    static constexpr size_t I1 = T_I1; ///< The input first dimension
    static constexpr size_t I2 = T_I2; ///< The input second dimension
    static constexpr size_t I3 = T_I3; ///< The input third dimension
    static constexpr size_t C1 = T_C1; ///< The pooling first dimension
    static constexpr size_t C2 = T_C2; ///< The pooling second dimension

    /*! The type used to store the weights */
    using weight = typename detail::get_type<weight_type<float>, Parameters...>::value;

    static_assert(C1 > 0, "Cannot shrink a layer by less than 1");
    static_assert(C2 > 0, "Cannot shrink a layer by less than 1");
    static_assert(I2 % C1 == 0, "Input dimension is not divisible by C");
    static_assert(I3 % C2 == 0, "Input dimension is not divisible by C");

    //Make sure only valid types are passed to the configuration list
    static_assert(
        detail::is_valid<cpp::type_list<weight_type_id>, Parameters...>::value,
        "Invalid parameters type for pooling_layer");
};

/*!
 * \brief Descriptor for a Dynamic 2D pooling layer desc
 */
template <typename... Parameters>
struct dyn_pooling_layer_2d_desc {
    /*! The type used to store the weights */
    using weight = typename detail::get_type<weight_type<float>, Parameters...>::value;

    //Make sure only valid types are passed to the configuration list
    static_assert(
        detail::is_valid<cpp::type_list<weight_type_id>, Parameters...>::value,
        "Invalid parameters type for pooling_layer");
};

/*!
 * \brief Descriptor for a 3D pooling layer desc
 */
template <size_t T_I1, size_t T_I2, size_t T_I3, size_t T_C1, size_t T_C2, size_t T_C3, typename... Parameters>
struct pooling_layer_3d_desc {
    static constexpr size_t I1 = T_I1; ///< The input first dimension
    static constexpr size_t I2 = T_I2; ///< The input second dimension
    static constexpr size_t I3 = T_I3; ///< The input third dimension
    static constexpr size_t C1 = T_C1; ///< The pooling first dimension
    static constexpr size_t C2 = T_C2; ///< The pooling second dimension
    static constexpr size_t C3 = T_C3; ///< The pooling third dimension

    /*! The type used to store the weights */
    using weight = typename detail::get_type<weight_type<float>, Parameters...>::value;

    static_assert(C1 > 0, "Cannot shrink a layer by less than 1");
    static_assert(C2 > 0, "Cannot shrink a layer by less than 1");
    static_assert(C3 > 0, "Cannot shrink a layer by less than 1");
    static_assert(I1 % C1 == 0, "Input dimension is not divisible by C");
    static_assert(I2 % C2 == 0, "Input dimension is not divisible by C");
    static_assert(I3 % C3 == 0, "Input dimension is not divisible by C");

    //Make sure only valid types are passed to the configuration list
    static_assert(
        detail::is_valid<cpp::type_list<weight_type_id>, Parameters...>::value,
        "Invalid parameters type for pooling_layer");
};

/*!
 * \brief Descriptor for a Dynamic 3D pooling layer desc
 */
template <typename... Parameters>
struct dyn_pooling_layer_3d_desc {
    /*! The type used to store the weights */
    using weight = typename detail::get_type<weight_type<float>, Parameters...>::value;

    //Make sure only valid types are passed to the configuration list
    static_assert(
        detail::is_valid<cpp::type_list<weight_type_id>, Parameters...>::value,
        "Invalid parameters type for pooling_layer");
};

} //end of dll namespace
