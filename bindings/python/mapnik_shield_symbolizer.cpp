/*****************************************************************************
 * 
 * This file is part of Mapnik (c++ mapping toolkit)
 *
 * Copyright (C) 2006 Artem Pavlenko, Jean-Francois Doyon
 * Copyright (C) 2006 10East Corp.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 *****************************************************************************/
//$Id$

#include <boost/python.hpp>
#include <mapnik/shield_symbolizer.hpp>

void export_shield_symbolizer()
{
    using namespace boost::python;
    using mapnik::shield_symbolizer;
    
    class_<shield_symbolizer>("ShieldSymbolizer",
                             init<>("Default Shield Symbolizer - 4x4 black square"))
        .def (init< std::string const&, std::string const&, unsigned, mapnik::Color const&,
              std::string const&, std::string const&,unsigned,unsigned>("TODO"))
        .add_property("avoid_edges",
                      &shield_symbolizer::get_avoid_edges,
                      &shield_symbolizer::set_avoid_edges)
        ;
    
}
