#ifndef COMMON_TYPES_HEADER
#define COMMON_TYPES_HEADER

#include <memory>
#include <iostream>

using uint8 = unsigned char;

struct Pixel{
	float r = 0;
	float g = 0;
	float b = 0;
	float a = 0;
};

struct ScreenPixel{
	uint8 r = 0;
	uint8 g = 0;
	uint8 b = 0;
	uint8 a = 0;
};

static void HandleError( cudaError_t err,const char *file,int line ) {
    if (err != cudaSuccess) {
        printf( "%s in %s at line %d\n", cudaGetErrorString( err ), file, line );
        exit( EXIT_FAILURE );
    }
}


#define HANDLE_ERROR( err ) (HandleError( err, __FILE__, __LINE__ ))

#define HANDLE_NULL( a ) {if (a == NULL) { \ printf( "Host memory failed in %s at line %d\n", \
                                    __FILE__, __LINE__ ); \
                            exit( EXIT_FAILURE );}}

template<typename T>
struct DataPair{
	T* cpuCopy = nullptr;
	T* gpuCopy = nullptr;
	int size;
};

#define DECLARE_DATA(typeName, variableName) \
	typeName* variableName = nullptr; \
	typeName* variableName##_GPUCopy = nullptr

#define COPY_DATA(destination,source,size) \
	std::memcpy(destination,source,size); \
	cudaMemcpy(destination##_GPUCopy,source##_GPUCopy,size,cudaMemcpyDeviceToDevice)

#define RELEASE_DATA(variableName)\
	delete variableName;\
	HANDLE_ERROR(cudaFree(variableName##_GPUCopy))

struct endl_flag{};
struct ostream_gpu{
	__device__ ostream_gpu& operator<<(const char* text){
		printf(text);
		return *this;
	};
	__device__ ostream_gpu& operator<<(int text){
		printf("%d",text);
		return *this;
	};
	__device__ ostream_gpu& operator<<(float text){
		printf("%.2f",text);
		return *this;
	};
	__device__ ostream_gpu& operator<<(endl_flag _){
		printf("\n");
		return *this;
	};
};

__constant__ ostream_gpu gout;
__constant__ endl_flag gendl;

#endif
