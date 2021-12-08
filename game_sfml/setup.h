#pragma once

// window scale
const int SCALE = 1200;

// grid element size constants
// the "_" at the end of a constant denotes that the constant is calculated automatically
// i.e. it is not modifiable.
const int yWIN = 1 * SCALE,
          xWIN = .7 * SCALE,

          CANVAS = .84 * xWIN,
          mCANVAS_ = (xWIN - CANVAS) * .5,

          TILE = .215 * CANVAS,
          mTILE_ = (CANVAS - TILE * 4) * .2,
          
          xRESET = .29 * CANVAS,
          yRESET = .38 * TILE,
          
          xSCORE = .85 * xRESET,
          ySCORE = .4 * xSCORE;