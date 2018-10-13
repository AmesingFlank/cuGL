#ifndef SHADER_HEADER
#define SHADER_HEADER

#include "DataBuffers.h"

class VertexShader{
public:
	VertexBuffer execute(const VertexBuffer& vertexBuffer){
		return VertexBuffer();
	};
	IndexedVertexBuffer execute(const IndexedVertexBuffer& vertexBuffer){
		return IndexedVertexBuffer();
	};
};

class PixelShader{
public:
	RenderBuffer execute(const PixelShaderInput& input){
		return RenderBuffer();
	};
};

class ShaderPair{
public:
	VertexShader* vertexShader;
	PixelShader* pixelShader;
};



#endif
