#ifndef ENDS_WITH_ENDS_WITH_HPP
#define ENDS_WITH_ENDS_WITH_HPP

template<typename matchee_iter, typename matcher_iter>
inline bool
ends_with(matchee_iter begin_matchee_iter, matchee_iter end_matchee_iter, matcher_iter begin_matcher_iter,
          matcher_iter end_matcher_iter)
{
    std::puts(__PRETTY_FUNCTION__);
    if (std::distance(begin_matcher_iter, end_matcher_iter) > std::distance(begin_matchee_iter, end_matchee_iter))
    { return false; }
    return std::equal(std::reverse_iterator<matcher_iter>(end_matcher_iter),
                      std::reverse_iterator<matcher_iter>(begin_matcher_iter),
                      std::reverse_iterator<matchee_iter>(end_matchee_iter));
}

template<typename matchee, typename matcher, std::size_t N>
inline
typename std::enable_if<std::is_constructible<matchee, const matcher (&)[N]>::value, bool>::type
ends_with(matchee const &e, const matcher (& r)[N])
{
    std::puts(__PRETTY_FUNCTION__);
    matchee const er(std::forward<matchee>(r));
    return ends_with(std::begin(e), std::end(e), std::begin(er), std::end(er));
}

template<typename matcher, typename matchee, std::size_t N>
inline
typename std::enable_if<std::is_constructible<matcher, const matchee (&)[N]>::value, bool>::type
ends_with(const matchee (& e)[N], matcher const &r)
{
    std::puts(__PRETTY_FUNCTION__);
    matcher const re(std::forward<const matchee (&)[N]>(e));
    return ends_with(std::begin(re), std::end(re), std::begin(r), std::end(r));
}

template<typename matchee, typename matcher>
inline
bool
ends_with(matchee const &e, matcher const &r)
{
    std::puts(__PRETTY_FUNCTION__);
    return ends_with(std::begin(e), std::end(e), std::begin(r), std::end(r));
}

#endif //ENDS_WITH_ENDS_WITH_HPP
