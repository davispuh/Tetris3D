// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.hpp"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files:
// #include <windows.h>

#define GLM_FORCE_RADIANS
#include <glm/fwd.hpp>
#include <glm/common.hpp>
#include <glm/matrix.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <GL/glew.h>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

#include <vector>

#include "BaseBlock.hpp"
#include "Block.hpp"
#include "Blocks/BlockI.hpp"
#include "Blocks/BlockJ.hpp"
#include "Blocks/BlockL.hpp"
#include "Blocks/BlockO.hpp"
#include "Blocks/BlockS.hpp"
#include "Blocks/BlockT.hpp"
#include "Blocks/BlockZ.hpp"
#include "BlockChooser.hpp"
#include "Shader.hpp"
#include "Field.hpp"
