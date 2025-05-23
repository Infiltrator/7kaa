/*
 * Seven Kingdoms: Ambition
 *
 * Copyright 2025 Tim Sviridov
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
 */

/**
 * @file
 *
 * Header file for Ambition::Entity.
 */

#pragma once

#include <boost/serialization/access.hpp>
#include <boost/serialization/nvp.hpp>
#include <boost/serialization/version.hpp>


namespace Ambition {

class Entity {
public:
  const unsigned long long int recordNumber;

  Entity(
    unsigned long long int recordNumber
  );

  virtual ~Entity() = default;

protected:
  friend class boost::serialization::access;

  /** To be used only by Boost serialisation. */
  Entity() :
    recordNumber()
  { }

  template<class Archive>
  void serialize(
    Archive& archive,
    const unsigned int version
  ) {
    archive & boost::serialization::make_nvp("recordNumber", const_cast<unsigned long long int&>(recordNumber));
  }
};

} // namespace Ambition

BOOST_CLASS_VERSION(Ambition::Entity, 0)
