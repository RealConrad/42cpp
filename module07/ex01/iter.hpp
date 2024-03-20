#ifndef ITER_HPP
# define ITER_HPP

/**
 * @brief Iterates over an array and applies `func` to each element.
 * @tparam T The type of the elements in the array. This should be a pointer type
 *           since `address` is expected to be the address of the first element
 *           of an array of type `T`.
 * @tparam L The type used to represent the length of the array.
 * @tparam Func The type of the function or callable object that will be applied to
 *              each element of the array. `Func` should be a type that can be invoked
 *              with a single argument of type `T` (more precisely, `*T` since `T` is
 *              expected to be a pointer type), and should return void. The function
 *              signature might look like `void funcName(const ElementType& element)`,
 *              where `ElementType` is the dereferenced type of `T`.
 * @param address A pointer to the first element of an array containing the elements
 *                over which `func` will be applied. This should match the type `T`.
 * @param length The number of elements in the array that `func` will be applied to.
 *               It is crucial that this accurately reflects the actual number of accessible
 *               elements starting from `address` to prevent undefined behavior.
 * @param func The function or callable object to be applied to each element of the array.
 *             This function or object must accept a single argument of the dereferenced type
 *             of `T` and return void.
 * @note The caller has to ensure that the length is correct. Passing an incorrect length can
 *       lead to undefined behavior, as the function does not perform bounds checking.
 */
template <typename T, typename L, typename Func>
void iter(T address, L length, Func func) {
	for (int i = 0; i < length; i++) {
		func(address[i]);
	}
}

#endif