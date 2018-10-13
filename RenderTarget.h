#ifndef RENDER_HEADER
#define RENDER_HEADER

#include "CommonTypes.h"
#include "Shader.h"
#include "Rasterizer.h"

class RenderTarget{
private:
	RenderBuffer renderBuffer;
public:
	ScreenPixel* getCurrentPixels(){
		return renderBuffer.pixels;
	}
	void drawTriangleArray(const VertexBuffer& vertexBuffer, const ShaderPair& shaderPair)
	{
		VertexBuffer vertexShaderResult = shaderPair.vertexShader->execute(vertexBuffer);
		PixelShaderInput pixelShaderInput = Rasterizer::rasterize(vertexShaderResult,renderBuffer.width,renderBuffer.height);
		RenderBuffer pixelShaderOutput = shaderPair.pixelShader->execute(pixelShaderInput);
		mergeIntoMainBuffer(pixelShaderOutput);
	}

	void drawIndexedTriangles(const IndexedVertexBuffer& indexedVertexBuffer,const ShaderPair& shaderPair)
	{
		IndexedVertexBuffer vertexShaderResult = shaderPair.vertexShader->execute(indexedVertexBuffer);
		PixelShaderInput pixelShaderInput = Rasterizer::rasterize(vertexShaderResult,renderBuffer.width,renderBuffer.height);
		RenderBuffer pixelShaderOutput = shaderPair.pixelShader->execute(pixelShaderInput);
		mergeIntoMainBuffer(pixelShaderOutput);
	}

	void mergeIntoMainBuffer(RenderBuffer newBuffer){

	}
};

#endif
