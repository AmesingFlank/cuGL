#ifndef RASTERIZER_HEADER
#define RASTERIZER_HEADER

#include "DataBuffers.h"
class Rasterizer{
public:
	static  PixelShaderInput rasterize(const VertexBuffer& vertexBuffer,int width,int height){
		return PixelShaderInput();
	}
	static  PixelShaderInput rasterize(const IndexedVertexBuffer& vertexBuffer,int width,int height){
			return PixelShaderInput();
		}

};

#endif
