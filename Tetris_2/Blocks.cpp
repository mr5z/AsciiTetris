#include "Blocks.h"

enum {O = EMPTY, X = PIVOT};

//7 kinds
//4 rotations
//5 columns
//5 rows

int Blocks [7][4][5][5] =
{
// Square
  {
   {
    {O, O, O, O, O},
    {O, O, O, O, O},
    {O, O, A, A, O},
    {O, O, A, A, O},
    {O, O, O, O, O}
    },
   {
    {O, O, O, O, O},
    {O, O, O, O, O},
    {O, O, A, A, O},
    {O, O, A, A, O},
    {O, O, O, O, O}
    },
   {
    {O, O, O, O, O},
    {O, O, O, O, O},
    {O, O, A, A, O},
    {O, O, A, A, O},
    {O, O, O, O, O}
    },
   {
    {O, O, O, O, O},
    {O, O, O, O, O},
    {O, O, A, A, O},
    {O, O, A, A, O},
    {O, O, O, O, O}
    }
   },

// I
  {
   {
    {O, O, O, O, O},
    {O, O, O, O, O},
    {O, B, B, B, B},
    {O, O, O, O, O},
    {O, O, O, O, O}
    },
   {
    {O, O, O, O, O},
    {O, O, B, O, O}, 
    {O, O, B, O, O},
    {O, O, B, O, O},
    {O, O, B, O, O}
    },
   {
    {O, O, O, O, O},
    {O, O, O, O, O},
    {B, B, B, B, O},
    {O, O, O, O, O},
    {O, O, O, O, O}
    },
   {
    {O, O, B, O, O},
    {O, O, B, O, O},
    {O, O, B, O, O},
    {O, O, B, O, O},
    {O, O, O, O, O}
    }
   }
  ,
// L
  {
   {
    {O, O, O, O, O},
    {O, O, C, O, O},
    {O, O, C, O, O},
    {O, O, C, C, O},
    {O, O, O, O, O}
    },
   {
    {O, O, O, O, O},
    {O, O, O, O, O},
    {O, C, C, C, O},
    {O, C, O, O, O},
    {O, O, O, O, O}
    },
   {
    {O, O, O, O, O},
    {O, C, C, O, O},
    {O, O, C, O, O},
    {O, O, C, O, O},
    {O, O, O, O, O}
    },
   {
    {O, O, O, O, O},
    {O, O, O, C, O},
    {O, C, C, C, O},
    {O, O, O, O, O},
    {O, O, O, O, O}
    }
   },
// L mirrored
  {
   {
    {O, O, O, O, O},
    {O, O, D, O, O},
    {O, O, D, O, O},
    {O, D, D, O, O},
    {O, O, O, O, O}
    },
   {
    {O, O, O, O, O},
    {O, D, O, O, O},
    {O, D, D, D, O},
    {O, O, O, O, O},
    {O, O, O, O, O}
    },
   {
    {O, O, O, O, O},
    {O, O, D, D, O},
    {O, O, D, O, O},
    {O, O, D, O, O},
    {O, O, O, O, O}
    },
   {
    {O, O, O, O, O},
    {O, O, O, O, O},
    {O, D, D, D, O},
    {O, O, O, D, O},
    {O, O, O, O, O}
    }
   },
// S
  {
   {
    {O, O, O, O, O},
    {O, O, O, O, O},
    {O, E, E, O, O},
    {O, O, E, E, O},
    {O, O, O, O, O}
    },
   {
    {O, O, O, O, O},
    {O, O, O, E, O},
    {O, O, E, E, O},
    {O, O, E, O, O},
    {O, O, O, O, O}
    },
   {
    {O, O, O, O, O},
    {O, E, E, O, O},
    {O, O, E, E, O},
    {O, O, O, O, O},
    {O, O, O, O, O}
    },
   {
    {O, O, O, O, O},
    {O, O, E, O, O},
    {O, E, E, O, O},
    {O, E, O, O, O},
    {O, O, O, O, O}
    }
   },
// S mirrored
  {
   {
    {O, O, O, O, O},
    {O, O, F, O, O},
    {O, O, F, F, O},
    {O, O, O, F, O},
    {O, O, O, O, O}
    },
   {
    {O, O, O, O, O},
    {O, O, O, O, O},
    {O, O, F, F, O},
    {O, F, F, O, O},
    {O, O, O, O, O}
    },
   {
    {O, O, O, O, O},
    {O, F, O, O, O},
    {O, F, F, O, O},
    {O, O, F, O, O},
    {O, O, O, O, O}
    },
   {
    {O, O, O, O, O},
    {O, O, F, F, O},
    {O, F, F, O, O},
    {O, O, O, O, O},
    {O, O, O, O, O}
    }
   },
// T
  {
   {
    {O, O, O, O, O},
    {O, O, G, O, O},
    {O, G, G, G, O},
    {O, O, O, O, O},
    {O, O, O, O, O}
    },
   {
    {O, O, O, O, O},
    {O, O, G, O, O},
    {O, O, G, G, O},
    {O, O, G, O, O},
    {O, O, O, O, O}
    },
   {
    {O, O, O, O, O},
    {O, O, O, O, O},
    {O, G, G, G, O},
    {O, O, G, O, O},
    {O, O, O, O, O}
    },
   {
    {O, O, O, O, O},
    {O, O, G, O, O},
    {O, G, G, O, O},
    {O, O, G, O, O},
    {O, O, O, O, O}
    }
   }
};

int blocksDisplacement1  [7][4][2] =
{
/* Square */
  {
	{-2, -3}, 
    {-2, -3},
    {-2, -3},
    {-2, -3}
   },
/* I */
  {
	{-2, -2},
    {-2, -3},
    {-2, -2},
    {-2, -3}
   },
/* L */
  {
	{-2, -3},
    {-2, -3},
    {-2, -3},
    {-2, -2}
   },
/* L mirrored */
  {
	{-2, -3},
    {-2, -2},
    {-2, -3},
    {-2, -3}
   },
/* S */
  {
	{-2, -3},
    {-2, -3},
    {-2, -3},
    {-2, -2}
   },
/* S mirrored */
  {
	{-2, -3},
    {-2, -3},
    {-2, -3},
    {-2, -2}
   },
/* T */
  {
	{-2, -3},
    {-2, -3},
    {-2, -3},
    {-2, -2}
   },
};

int blocksDisplacement2  [7][4][2] =
{
/* Square */
  {
	{14, 5}, 
    {14, 5},
    {14, 5},
    {14, 5}
   },
/* I */
  {
	{14, 6},
    {14, 5},
    {14, 6},
    {14, 5}
   },
/* L */
  {
	{14, 5},
    {14, 5},
    {14, 5},
    {14, 6}
   },
/* L mirrored */
  {
	{14, 5},
    {14, 6},
    {14, 5},
    {14, 5}
   },
/* S */
  {
	{14, 5},
    {14, 5},
    {14, 5},
    {14, 6}
   },
/* S mirrored */
  {
	{14, 5},
    {14, 5},
    {14, 5},
    {14, 6}
   },
/* T */
  {
	{14, 5},
    {14, 5},
    {14, 5},
    {14, 6}
   },
};

	int CBlocks::SetBlockType(eCells pType,int pRotation, int bX, int bY)
		{
		return Blocks [pType][pRotation][bX][bY];
		}

	int CBlocks::GetXInitialPosition (eCells nType,int nRotation)
		{
		return blocksDisplacement1 [nType][nRotation][0];
		}

	int CBlocks::GetYInitialPosition (eCells nType,int nRotation)
		{
		return blocksDisplacement1 [nType][nRotation][1];
		}

	int CBlocks::GetmXInitialPosition(eCells nType, int nRotation)
		{
		return blocksDisplacement2[nType][nRotation][0];
		}

	int CBlocks::GetmYInitialPosition(eCells nType, int nRotation)
		{
		return blocksDisplacement2[nType][nRotation][1];
		}

//int Blocks [7][4][5][5] =
//{
//// Square
//  {
//   {
//    {O, O, O, O, O},
//    {O, O, O, O, O},
//    {O, O, X, A, O},
//    {O, O, A, A, O},
//    {O, O, O, O, O}
//    },
//   {
//    {O, O, O, O, O},
//    {O, O, O, O, O},
//    {O, O, X, A, O},
//    {O, O, A, A, O},
//    {O, O, O, O, O}
//    },
//   {
//    {O, O, O, O, O},
//    {O, O, O, O, O},
//    {O, O, X, A, O},
//    {O, O, A, A, O},
//    {O, O, O, O, O}
//    },
//   {
//    {O, O, O, O, O},
//    {O, O, O, O, O},
//    {O, O, X, A, O},
//    {O, O, A, A, O},
//    {O, O, O, O, O}
//    }
//   },
//
//// I
//  {
//   {
//    {O, O, O, O, O},
//    {O, O, O, O, O},
//    {O, B, X, B, B},
//    {O, O, O, O, O},
//    {O, O, O, O, O}
//    },
//   {
//    {O, O, O, O, O},
//    {O, O, B, O, O}, 
//    {O, O, X, O, O},
//    {O, O, B, O, O},
//    {O, O, B, O, O}
//    },
//   {
//    {O, O, O, O, O},
//    {O, O, O, O, O},
//    {B, B, X, B, O},
//    {O, O, O, O, O},
//    {O, O, O, O, O}
//    },
//   {
//    {O, O, B, O, O},
//    {O, O, B, O, O},
//    {O, O, X, O, O},
//    {O, O, B, O, O},
//    {O, O, O, O, O}
//    }
//   }
//  ,
//// L
//  {
//   {
//    {O, O, O, O, O},
//    {O, O, C, O, O},
//    {O, O, X, O, O},
//    {O, O, C, C, O},
//    {O, O, O, O, O}
//    },
//   {
//    {O, O, O, O, O},
//    {O, O, O, O, O},
//    {O, C, X, C, O},
//    {O, C, O, O, O},
//    {O, O, O, O, O}
//    },
//   {
//    {O, O, O, O, O},
//    {O, C, C, O, O},
//    {O, O, X, O, O},
//    {O, O, C, O, O},
//    {O, O, O, O, O}
//    },
//   {
//    {O, O, O, O, O},
//    {O, O, O, C, O},
//    {O, C, X, C, O},
//    {O, O, O, O, O},
//    {O, O, O, O, O}
//    }
//   },
//// L mirrored
//  {
//   {
//    {O, O, O, O, O},
//    {O, O, D, O, O},
//    {O, O, X, O, O},
//    {O, D, D, O, O},
//    {O, O, O, O, O}
//    },
//   {
//    {O, O, O, O, O},
//    {O, D, O, O, O},
//    {O, D, X, D, O},
//    {O, O, O, O, O},
//    {O, O, O, O, O}
//    },
//   {
//    {O, O, O, O, O},
//    {O, O, D, D, O},
//    {O, O, X, O, O},
//    {O, O, D, O, O},
//    {O, O, O, O, O}
//    },
//   {
//    {O, O, O, O, O},
//    {O, O, O, O, O},
//    {O, D, X, D, O},
//    {O, O, O, D, O},
//    {O, O, O, O, O}
//    }
//   },
//// S
//  {
//   {
//    {O, O, O, O, O},
//    {O, O, O, O, O},
//    {O, E, X, O, O},
//    {O, O, E, E, O},
//    {O, O, O, O, O}
//    },
//   {
//    {O, O, O, O, O},
//    {O, O, O, E, O},
//    {O, O, X, E, O},
//    {O, O, E, O, O},
//    {O, O, O, O, O}
//    },
//   {
//    {O, O, O, O, O},
//    {O, E, E, O, O},
//    {O, O, X, E, O},
//    {O, O, O, O, O},
//    {O, O, O, O, O}
//    },
//   {
//    {O, O, O, O, O},
//    {O, O, E, O, O},
//    {O, E, X, O, O},
//    {O, E, O, O, O},
//    {O, O, O, O, O}
//    }
//   },
//// S mirrored
//  {
//   {
//    {O, O, O, O, O},
//    {O, O, F, O, O},
//    {O, O, X, F, O},
//    {O, O, O, F, O},
//    {O, O, O, O, O}
//    },
//   {
//    {O, O, O, O, O},
//    {O, O, O, O, O},
//    {O, O, X, F, O},
//    {O, F, F, O, O},
//    {O, O, O, O, O}
//    },
//   {
//    {O, O, O, O, O},
//    {O, F, O, O, O},
//    {O, F, X, O, O},
//    {O, O, F, O, O},
//    {O, O, O, O, O}
//    },
//   {
//    {O, O, O, O, O},
//    {O, O, F, F, O},
//    {O, F, X, O, O},
//    {O, O, O, O, O},
//    {O, O, O, O, O}
//    }
//   },
//// T
//  {
//   {
//    {O, O, O, O, O},
//    {O, O, G, O, O},
//    {O, G, X, G, O},
//    {O, O, O, O, O},
//    {O, O, O, O, O}
//    },
//   {
//    {O, O, O, O, O},
//    {O, O, G, O, O},
//    {O, O, X, G, O},
//    {O, O, G, O, O},
//    {O, O, O, O, O}
//    },
//   {
//    {O, O, O, O, O},
//    {O, O, O, O, O},
//    {O, G, X, G, O},
//    {O, O, G, O, O},
//    {O, O, O, O, O}
//    },
//   {
//    {O, O, O, O, O},
//    {O, O, G, O, O},
//    {O, G, X, O, O},
//    {O, O, G, O, O},
//    {O, O, O, O, O}
//    }
//   }
//};
