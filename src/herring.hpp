//  $Id$
//
//  SuperTuxKart - a fun racing game with go-kart
//  Copyright (C) 2004 Steve Baker <sjbaker1@airmail.net>
//
//  This program is free software; you can redistribute it and/or
//  modify it under the terms of the GNU General Public License
//  as published by the Free Software Foundation; either version 3
//  of the License, or (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

#ifndef HEADER_HERRING_H
#define HEADER_HERRING_H

// num_players triggers  'already defined' messages without the WINSOCKAPI define. Don't ask me :(
#define _WINSOCKAPI_
#include <plib/sg.h>
#include "coord.hpp"

class Kart;
class ssgTransform;
class ssgEntity;

// HE_RED must be the first, HE_SILVER the last entry. See HerringManager
enum herringType { HE_RED, HE_GREEN, HE_GOLD, HE_SILVER, HE_NONE };

// -----------------------------------------------------------------------------
class Herring
{
private:
    herringType   m_type;         // Herring type
    bool          m_eaten;        // true if herring  was eaten & is not displayed
    float         m_time_till_return;  // time till an eaten herring reappears
    Coord         m_coord;        // Original coordinates, used mainly when
                                  // eaten herrings reappear.
    ssgTransform* m_root;         // The actual root of the herring
    unsigned int  m_herring_id;   // index in herring_manager field
public:
                  Herring (herringType type, const Vec3& xyz, ssgEntity* model,
                           unsigned int herring_id);
                 ~Herring ();
    unsigned int  getHerringId() const {return m_herring_id; }
    void          update  (float delta);
    void          isEaten ();
    int           hitKart (Kart* kart );
    void          reset   ();
    ssgTransform* getRoot () const {return m_root;}
    herringType   getType () const {return m_type;}
    bool          wasEaten() const {return m_eaten;}
}
;   // class Herring

#endif
