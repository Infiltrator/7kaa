/*
 * Seven Kingdoms: Ancient Adversaries
 *
 * Copyright 2010 Unavowed <unavowed@vexillium.org>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#include <output_stream.h>

#include <stdint.h>


/*
 * Writes a non-integer little-endian value of the same size as the integer
 * type AliasT.
 */
template <typename T, typename AliasT>
bool write_le_alias(OutputStream *os, T val)
{
   union { T val; AliasT al; } u;
   u.val = val;
   return write_le_integer<AliasT>(os, u.al);
}

template <>
bool write_le<float>(OutputStream *os, float val)
{
   return write_le_alias<float, uint32_t>(os, val);
}

template <>
bool write_le<double>(OutputStream *os, double val)
{
   return write_le_alias<double, uint64_t>(os, val);
}
