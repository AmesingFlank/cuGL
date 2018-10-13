#ifndef DATA_BUFFER_HEADER
#define DATA_BUFFER_HEADER

#include "CommonTypes.h"

struct VertexBuffer{
	DECLARE_DATA(float,vertexData);
	int vertexCount = 0;
	int componentCount = 0;
	VertexBuffer(){

	}
	VertexBuffer(const VertexBuffer& copy){
		vertexCount = copy.vertexCount;
		componentCount = copy.componentCount;
		COPY_DATA(vertexData,copy.vertexData, vertexCount*componentCount*sizeof(float));
	}
	VertexBuffer& operator=(const VertexBuffer& copy){
		vertexCount = copy.vertexCount;
		componentCount = copy.componentCount;
		COPY_DATA(vertexData,copy.vertexData, vertexCount*componentCount*sizeof(float));
		return *this;
	}
	~VertexBuffer(){
		RELEASE_DATA(vertexData);
	}
};

struct IndexBuffer{
	DECLARE_DATA(int,indexData);
	int trianglesCount = 0;
	IndexBuffer(){

	}
	IndexBuffer(const IndexBuffer& copy){
		trianglesCount = copy.trianglesCount;
		COPY_DATA(indexData,copy.indexData, trianglesCount*3*sizeof(int));
	}
	IndexBuffer& operator=(const IndexBuffer& copy){
		trianglesCount = copy.trianglesCount;
		COPY_DATA(indexData,copy.indexData, trianglesCount*3*sizeof(int));
		return *this;
	}
	~IndexBuffer(){
		RELEASE_DATA(indexData);
	}
};

struct IndexedVertexBuffer{
	VertexBuffer vertexBuffer;
	IndexBuffer indexBuffer;
	IndexedVertexBuffer(){

	}
	IndexedVertexBuffer(const IndexedVertexBuffer& copy):vertexBuffer(copy.vertexBuffer),indexBuffer(copy.indexBuffer){

	}
	IndexedVertexBuffer& operator=(const IndexedVertexBuffer& copy){
		vertexBuffer = copy.vertexBuffer;
		indexBuffer = copy.indexBuffer;
		return *this;
	}
};

struct RenderBuffer{
	DECLARE_DATA(ScreenPixel,pixels);
	DECLARE_DATA(float,zBuffer);
	DECLARE_DATA(bool,stencilBuffer);
	int width = 0;
	int height = 0;
	RenderBuffer(){

	}
	RenderBuffer(const RenderBuffer& copy){
		width = copy.width;
		height = copy.height;
		COPY_DATA(pixels,copy.pixels, width*height*sizeof(ScreenPixel));
		COPY_DATA(zBuffer,copy.zBuffer, width*height*sizeof(float));
		COPY_DATA(stencilBuffer,stencilBuffer.pixels, width*height*sizeof(bool));
	}
	RenderData& operator=(const RenderBuffer& copy){
		width = copy.width;
		height = copy.height;
		COPY_DATA(pixels,copy.pixels, width*height*sizeof(ScreenPixel));
		COPY_DATA(zBuffer,copy.zBuffer, width*height*sizeof(float));
		COPY_DATA(stencilBuffer,stencilBuffer.pixels, width*height*sizeof(bool));
		return this;
	}
	~RenderBuffer(){
		RELEASE_DATA(pixels);
		RELEASE_DATA(zBuffer);
		RELEASE_DATA(stencilBuffer);
	}
};

struct PixelShaderInput{
	DECLARE_DATA(float,data);
	int pixelCount = 0;
	int componentCount = 0;
};


#endif
