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

template<typename InIter, typename OutIter>
inline bool
ends_with(InIter &&firstValueIter, InIter &&lastValueIter, OutIter &&firstPostfixIter)
{
    if (std::distance(firstPostfixIter, OutIter(std::reverse_iterator<OutIter>(firstPostfixIter).base())) > std::distance(firstValueIter, lastValueIter))
    { return false; }
    return std::equal(firstPostfixIter, OutIter(std::reverse_iterator<OutIter>(firstPostfixIter).base()), firstValueIter);
}

#endif //ENDS_WITH_ENDS_WITH_HPP
