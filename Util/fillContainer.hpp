#pragma once
#include <cstdint>
#include <type_traits>
#include <functional>

/**
 * @brief fillContainer() (コンテナのfill)
 */
template <class T, class Container, class... ConstructorArgs, std::enable_if_t<std::is_same<Container, T>::value, std::nullptr_t> = nullptr>
inline void fillContainer(Container& container, ConstructorArgs&&... constructorArgs) {
    container = T(std::forward<ConstructorArgs>(constructorArgs)...);
}

template <class T, class Container, class... ConstructorArgs, std::enable_if_t<!std::is_same<Container, T>::value, std::nullptr_t> = nullptr>
inline void fillContainer(Container& container, ConstructorArgs&&... constructorArgs) {
    for (auto& e: container) fillContainer<T>(e, std::forward<ConstructorArgs>(constructorArgs)...);
}
