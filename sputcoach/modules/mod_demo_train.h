/*
Brainstormers 2D (Soccer Simulation League 2D)
PUBLIC SOURCE CODE RELEASE 2005
Copyright (C) 1998-2005 Neuroinformatics Group,
                        University of Osnabrueck, Germany

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

/* Author: FluffyBunny
 *
 * This shall demonstrate offline coach capabilities.
 *
 */

#ifndef _MOD_DEMO_TRAIN_H_
#define _MOD_DEMO_TRAIN_H_

#include "defs.h"
#include "coach.h"
#include "param.h"
#include "field.h"
#include "options.h"
#include "modules.h"
#include "messages.h"

class ModDemoTrain : public AbstractModule {

  long cyc_cnt;
  long runs;
  long misses;
  Value cyc_avg;
  Value diff_avg;
  
 public:

  bool init(int argc,char **argv);             /** init the module */
  bool destroy();                              /** tidy up         */
  
  bool behave();                               /** called once per cycle, after visual update   */
  bool onRefereeMessage(bool PMChange);        /** called on playmode change or referee message */
  bool onHearMessage(const char *str);         /** called on every hear message from any player */
  bool onKeyboardInput(const char *str);       /** called on keyboard input                     */
  bool onChangePlayerType(bool,int,int=-1);    /** SEE mod_template.c!                          */

  void moveBall(Value x,Value y,Value velx=0,Value vely=0);
  void moveOwnPlayer(int unum,Value x,Value y,Value dir=0,Value velx=0,Value vely=0);
  void moveOppPlayer(int unum,Value x,Value y,Value dir=0,Value velx=0,Value vely=0);
  
  static const char modName[];                 /** module name, should be same as class name    */
  const char *getModName() {return modName;}   /** do not change this!                          */
};

#endif
