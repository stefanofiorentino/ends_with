/*
 * Copyright © 2011-2018 BTicino S.p.A.
 * 
 * This file is part of bt_drover.
 * 
 * bt_drover is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * bt_drover is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with bt_drover. If not, see <http://www.gnu.org/licenses/>.
 * 
 * 
 */
#ifndef ENDS_WITH_ENDS_WITH_HPP
#define ENDS_WITH_ENDS_WITH_HPP

template<typename T>
struct has_size
{
    typedef char one;
    typedef long two;

    template<typename C>
    static one test(typeof(&C::size))
    {
        return one{};
    };

    template<typename C>
    static two test(...)
    {
        return two{};
    };

    enum
    {
        value = sizeof(test<T>(0)) == sizeof(char)
    };
};

inline bool ends_with(...);

template<typename InIter, typename OutIter>
inline bool
ends_with(InIter &&firstValueIter, InIter &&lastValueIter, OutIter &&firstPostfixIter)
{
    if (std::distance(firstPostfixIter, OutIter(std::reverse_iterator<OutIter>(firstPostfixIter).base())) > std::distance(firstValueIter, lastValueIter))
    { return false; }
    return std::equal(firstPostfixIter, OutIter(std::reverse_iterator<OutIter>(firstPostfixIter).base()), firstValueIter);
}

template<typename T>
inline
typename std::enable_if<has_size<T>::value, bool>::type
ends_with(T const &value, T const &postfix)
{
    return ends_with(std::begin(value), std::end(value), std::begin(postfix));
}

inline bool ends_with(std::string const &value, const char *postfix)
{
    return ends_with(value, std::string(postfix));
}

inline bool ends_with(const char *value, std::string const &postfix)
{
    return ends_with(std::string(value), postfix);
}

inline bool ends_with(const char *value, const char *postfix)
{
    return ends_with(std::string(value), std::string(postfix));
}

#endif //ENDS_WITH_ENDS_WITH_HPP
