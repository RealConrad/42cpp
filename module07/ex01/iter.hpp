#ifndef ITER_HPP
#define ITER_HPP

template <typename T, typename L, typename Func>
void iter(T address, L length, Func func) {
	for (int i = 0; i < length; i++) {
		func(address[i]);
	}
}

#endif