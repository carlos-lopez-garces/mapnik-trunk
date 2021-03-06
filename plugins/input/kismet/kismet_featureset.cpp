/*****************************************************************************
 * 
 * This file is part of Mapnik (c++ mapping toolkit)
 *
 * Copyright (C) 2007 Artem Pavlenko
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

#include <mapnik/global.hpp>
#include <mapnik/datasource.hpp>
#include <mapnik/box2d.hpp>
#include <mapnik/geometry.hpp>
#include <mapnik/feature.hpp>
#include <mapnik/feature_layer_desc.hpp>
#include <mapnik/wkb.hpp>
#include <mapnik/unicode.hpp>

#include "kismet_featureset.hpp"

using mapnik::Feature;
using mapnik::feature_ptr;
using mapnik::geometry_type;
using mapnik::geometry_utils;
using mapnik::transcoder;

kismet_featureset::kismet_featureset(const std::list<kismet_network_data> &knd_list,
                                     std::string const& encoding)
    : knd_list_(knd_list),
      tr_(new transcoder(encoding)),
      feature_id (0),
      knd_list_it(knd_list_.begin ()),
      source_("+proj=longlat +ellps=WGS84 +datum=WGS84 +no_defs")
{
}

kismet_featureset::~kismet_featureset()
{
}

feature_ptr kismet_featureset::next()
{
    if (knd_list_it != knd_list_.end ())
    {
        const kismet_network_data& knd = *knd_list_it;
        const std::string key = "internet_access";

        std::string value;
        if (knd.crypt_ == crypt_none)
        {
            value = "wlan_uncrypted";
        }
        else if (knd.crypt_ == crypt_wep)
        {
            value = "wlan_wep";
        }
        else
        {
            value = "wlan_crypted";
        }

        feature_ptr feature(new Feature(feature_id));
      
        geometry_type* pt = new geometry_type(mapnik::Point);
        pt->move_to(knd.bestlon_, knd.bestlat_);
        feature->add_geometry(pt);
      
        boost::put(*feature, key, tr_->transcode(value.c_str()));
      
        ++feature_id;
        ++knd_list_it;
        
        return feature;
    }
    
    return feature_ptr();
}

