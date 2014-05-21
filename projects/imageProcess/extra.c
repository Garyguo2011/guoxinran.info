#include <emmintrin.h>
#include <omp.h>
int conv2D(float* in, float* out, int data_size_X, int data_size_Y,
                    float* kernel, int kernel_x, int kernel_y)
{
    // the x coordinate of the kernel's center
    int kern_cent_X = (kernel_x - 1)/2;
    // the y coordinate of the kernel's center
    int kern_cent_Y = (kernel_y - 1)/2;


    float padZero[4] = {0.0, 0.0, 0.0, 0.0};

	int kernel_size = kernel_x * kernel_y;
    float* ker = (float*) malloc(kernel_x * kernel_y * sizeof(float));

// Pading Zero =================================================================================
    int padSize_X = data_size_X + 2*kern_cent_X;
    int padSize_Y = data_size_Y + 2*kern_cent_Y;
	float* padIn = (float*) malloc(padSize_X * padSize_Y * sizeof(float));

	
	#pragma omp parallel for
	for(int y = 0; y < kern_cent_Y; y++){
		for(int x = 0; x < padSize_X; x++){
			padIn[x + y * padSize_X] = 0;
		}
	}

	#pragma omp parallel for
	for(int y = kern_cent_Y; y < kern_cent_Y + data_size_Y; y++){		

		for(int x = 0; x < kern_cent_X; x++){
			padIn[x + y * padSize_X] = 0;	
		}		

		for(int x = kern_cent_X; x < kern_cent_X + (data_size_X)/96*96; x+=96){
			_mm_storeu_ps((float*)(padIn + x + y * padSize_X), _mm_loadu_ps((float*)(in + (x-kern_cent_X) + (y-kern_cent_Y) * data_size_X)));
			_mm_storeu_ps((float*)(padIn + x + 4 + y * padSize_X), _mm_loadu_ps((float*)(in + (x + 4 -kern_cent_X) + (y-kern_cent_Y) * data_size_X)));
			_mm_storeu_ps((float*)(padIn + x + 8 + y * padSize_X), _mm_loadu_ps((float*)(in + (x + 8 -kern_cent_X) + (y-kern_cent_Y) * data_size_X)));
			_mm_storeu_ps((float*)(padIn + x + 12 + y * padSize_X), _mm_loadu_ps((float*)(in + (x + 12 -kern_cent_X) + (y-kern_cent_Y) * data_size_X)));
			_mm_storeu_ps((float*)(padIn + x + 16 + y * padSize_X), _mm_loadu_ps((float*)(in + (x + 16 -kern_cent_X) + (y-kern_cent_Y) * data_size_X)));
			_mm_storeu_ps((float*)(padIn + x + 20 + y * padSize_X), _mm_loadu_ps((float*)(in + (x + 20 -kern_cent_X) + (y-kern_cent_Y) * data_size_X)));
			_mm_storeu_ps((float*)(padIn + x + 24 + y * padSize_X), _mm_loadu_ps((float*)(in + (x + 24 -kern_cent_X) + (y-kern_cent_Y) * data_size_X)));
			_mm_storeu_ps((float*)(padIn + x + 28 + y * padSize_X), _mm_loadu_ps((float*)(in + (x + 28 -kern_cent_X) + (y-kern_cent_Y) * data_size_X)));
			_mm_storeu_ps((float*)(padIn + x + 32 + y * padSize_X), _mm_loadu_ps((float*)(in + (x + 32 -kern_cent_X) + (y-kern_cent_Y) * data_size_X)));
			_mm_storeu_ps((float*)(padIn + x + 36 + y * padSize_X), _mm_loadu_ps((float*)(in + (x + 36 -kern_cent_X) + (y-kern_cent_Y) * data_size_X)));
			_mm_storeu_ps((float*)(padIn + x + 40 + y * padSize_X), _mm_loadu_ps((float*)(in + (x + 40 -kern_cent_X) + (y-kern_cent_Y) * data_size_X)));
			_mm_storeu_ps((float*)(padIn + x + 44 + y * padSize_X), _mm_loadu_ps((float*)(in + (x + 44 -kern_cent_X) + (y-kern_cent_Y) * data_size_X)));
			_mm_storeu_ps((float*)(padIn + x + 48 + y * padSize_X), _mm_loadu_ps((float*)(in + (x + 48 -kern_cent_X) + (y-kern_cent_Y) * data_size_X)));
			_mm_storeu_ps((float*)(padIn + x + 52 + y * padSize_X), _mm_loadu_ps((float*)(in + (x + 52 -kern_cent_X) + (y-kern_cent_Y) * data_size_X)));
			_mm_storeu_ps((float*)(padIn + x + 56 + y * padSize_X), _mm_loadu_ps((float*)(in + (x + 56 -kern_cent_X) + (y-kern_cent_Y) * data_size_X)));
			_mm_storeu_ps((float*)(padIn + x + 60 + y * padSize_X), _mm_loadu_ps((float*)(in + (x + 60 -kern_cent_X) + (y-kern_cent_Y) * data_size_X)));
			_mm_storeu_ps((float*)(padIn + x + 64 + y * padSize_X), _mm_loadu_ps((float*)(in + (x + 64 -kern_cent_X) + (y-kern_cent_Y) * data_size_X)));
			_mm_storeu_ps((float*)(padIn + x + 68 + y * padSize_X), _mm_loadu_ps((float*)(in + (x + 68 -kern_cent_X) + (y-kern_cent_Y) * data_size_X)));
			_mm_storeu_ps((float*)(padIn + x + 72 + y * padSize_X), _mm_loadu_ps((float*)(in + (x + 72 -kern_cent_X) + (y-kern_cent_Y) * data_size_X)));
			_mm_storeu_ps((float*)(padIn + x + 76 + y * padSize_X), _mm_loadu_ps((float*)(in + (x + 76 -kern_cent_X) + (y-kern_cent_Y) * data_size_X)));
			_mm_storeu_ps((float*)(padIn + x + 80 + y * padSize_X), _mm_loadu_ps((float*)(in + (x + 80 -kern_cent_X) + (y-kern_cent_Y) * data_size_X)));
			_mm_storeu_ps((float*)(padIn + x + 84 + y * padSize_X), _mm_loadu_ps((float*)(in + (x + 84 -kern_cent_X) + (y-kern_cent_Y) * data_size_X)));
			_mm_storeu_ps((float*)(padIn + x + 88 + y * padSize_X), _mm_loadu_ps((float*)(in + (x + 88 -kern_cent_X) + (y-kern_cent_Y) * data_size_X)));
			_mm_storeu_ps((float*)(padIn + x + 92 + y * padSize_X), _mm_loadu_ps((float*)(in + (x + 92 -kern_cent_X) + (y-kern_cent_Y) * data_size_X)));
		}

		for(int x = kern_cent_X+(data_size_X)/96*96; x < padSize_X - kern_cent_X; x++){
			padIn[x + y * padSize_X] = in[(x-kern_cent_X) + (y-kern_cent_Y) * data_size_X];
		}

		for(int x = padSize_X - kern_cent_X; x < padSize_X; x++){
			padIn[x + y * padSize_X] = 0;
		}
	}

	#pragma omp parallel for
	for(int y = kern_cent_Y + data_size_Y; y < padSize_Y; y++){
		for(int x = 0; x < padSize_X; x++){
			padIn[x + y * padSize_X] = 0;
		}
	}
//=================================================================================

// Reverse kernel =================================================================
    #pragma omp parallel for
    for(int j = 0; j < kernel_y; j++){
    	for(int i = 0; i < kernel_x; i++){
    		ker[i + j * kernel_x] = kernel[kernel_size - 1 - (i + j * kernel_x)];
    	}
    }
//=================================================================================

// Main Calculation =================================================================
    #pragma omp parallel for
	for(int y = 0; y < data_size_Y; y++){

		for(int x = 0; x < data_size_X/96*96; x+=96){
			
			__m128 out_matrix1 = _mm_loadu_ps((float*)(out + x + y * data_size_X));
			__m128 out_matrix2 = _mm_loadu_ps((float*)(out + x + 4 + y * data_size_X));
			__m128 out_matrix3 = _mm_loadu_ps((float*)(out + x + 8 + y * data_size_X));
			__m128 out_matrix4 = _mm_loadu_ps((float*)(out + x + 12 + y * data_size_X));
			__m128 out_matrix5 = _mm_loadu_ps((float*)(out + x + 16 + y * data_size_X));
			__m128 out_matrix6 = _mm_loadu_ps((float*)(out + x + 20 + y * data_size_X));
			__m128 out_matrix7 = _mm_loadu_ps((float*)(out + x + 24 + y * data_size_X));
			__m128 out_matrix8 = _mm_loadu_ps((float*)(out + x + 28 + y * data_size_X));
			__m128 out_matrix9 = _mm_loadu_ps((float*)(out + x + 32 + y * data_size_X));
			__m128 out_matrix10 = _mm_loadu_ps((float*)(out + x + 36 + y * data_size_X));
			__m128 out_matrix11 = _mm_loadu_ps((float*)(out + x + 40 + y * data_size_X));
			__m128 out_matrix12 = _mm_loadu_ps((float*)(out + x + 44 + y * data_size_X));
			__m128 out_matrix13 = _mm_loadu_ps((float*)(out + x + 48 + y * data_size_X));
			__m128 out_matrix14 = _mm_loadu_ps((float*)(out + x + 52 + y * data_size_X));
			__m128 out_matrix15 = _mm_loadu_ps((float*)(out + x + 56 + y * data_size_X));
			__m128 out_matrix16 = _mm_loadu_ps((float*)(out + x + 60 + y * data_size_X));
			__m128 out_matrix17 = _mm_loadu_ps((float*)(out + x + 64 + y * data_size_X));
			__m128 out_matrix18 = _mm_loadu_ps((float*)(out + x + 68 + y * data_size_X));
			__m128 out_matrix19 = _mm_loadu_ps((float*)(out + x + 72 + y * data_size_X));
			__m128 out_matrix20 = _mm_loadu_ps((float*)(out + x + 76 + y * data_size_X));
			__m128 out_matrix21 = _mm_loadu_ps((float*)(out + x + 80 + y * data_size_X));
			__m128 out_matrix22 = _mm_loadu_ps((float*)(out + x + 84 + y * data_size_X));
			__m128 out_matrix23 = _mm_loadu_ps((float*)(out + x + 88 + y * data_size_X));
			__m128 out_matrix24 = _mm_loadu_ps((float*)(out + x + 92 + y * data_size_X));
			// __m128 out_matrix25 = _mm_loadu_ps((float*)(out + x + 96 + y * data_size_X));
			// __m128 out_matrix26 = _mm_loadu_ps((float*)(out + x + 100 + y * data_size_X));
			// __m128 out_matrix27 = _mm_loadu_ps((float*)(out + x + 104 + y * data_size_X));
			// __m128 out_matrix28 = _mm_loadu_ps((float*)(out + x + 108 + y * data_size_X));
			// __m128 out_matrix29 = _mm_loadu_ps((float*)(out + x + 112 + y * data_size_X));


			for(int j = 0; j < kernel_y; j++){
				for(int i = 0; i < kernel_x; i++){
					__m128 element = _mm_load1_ps((float*)(ker + i + j * kernel_x));

					out_matrix1 = _mm_add_ps(_mm_mul_ps(element, _mm_loadu_ps((float*)(padIn + (x+i) + (y+j) * padSize_X))), out_matrix1);
					out_matrix2 = _mm_add_ps(_mm_mul_ps(element, _mm_loadu_ps((float*)(padIn + (x+i) + 4 + (y+j) * padSize_X))), out_matrix2);
					out_matrix3 = _mm_add_ps(_mm_mul_ps(element, _mm_loadu_ps((float*)(padIn + (x+i) + 8 + (y+j) * padSize_X))), out_matrix3);
					out_matrix4 = _mm_add_ps(_mm_mul_ps(element, _mm_loadu_ps((float*)(padIn + (x+i) + 12 + (y+j) * padSize_X))), out_matrix4);
					out_matrix5 = _mm_add_ps(_mm_mul_ps(element, _mm_loadu_ps((float*)(padIn + (x+i) + 16 + (y+j) * padSize_X))), out_matrix5);
					out_matrix6 = _mm_add_ps(_mm_mul_ps(element, _mm_loadu_ps((float*)(padIn + (x+i) + 20 + (y+j) * padSize_X))), out_matrix6);
					out_matrix7 = _mm_add_ps(_mm_mul_ps(element, _mm_loadu_ps((float*)(padIn + (x+i) + 24 + (y+j) * padSize_X))), out_matrix7);
					out_matrix8 = _mm_add_ps(_mm_mul_ps(element, _mm_loadu_ps((float*)(padIn + (x+i) + 28 + (y+j) * padSize_X))), out_matrix8);
					out_matrix9 = _mm_add_ps(_mm_mul_ps(element, _mm_loadu_ps((float*)(padIn + (x+i) + 32 + (y+j) * padSize_X))), out_matrix9);
					out_matrix10 = _mm_add_ps(_mm_mul_ps(element, _mm_loadu_ps((float*)(padIn + (x+i) + 36 + (y+j) * padSize_X))), out_matrix10);
					out_matrix11 = _mm_add_ps(_mm_mul_ps(element, _mm_loadu_ps((float*)(padIn + (x+i) + 40 + (y+j) * padSize_X))), out_matrix11);
					out_matrix12 = _mm_add_ps(_mm_mul_ps(element, _mm_loadu_ps((float*)(padIn + (x+i) + 44 + (y+j) * padSize_X))), out_matrix12);
					out_matrix13 = _mm_add_ps(_mm_mul_ps(element, _mm_loadu_ps((float*)(padIn + (x+i) + 48 + (y+j) * padSize_X))), out_matrix13);
					out_matrix14 = _mm_add_ps(_mm_mul_ps(element, _mm_loadu_ps((float*)(padIn + (x+i) + 52 + (y+j) * padSize_X))), out_matrix14);
					out_matrix15 = _mm_add_ps(_mm_mul_ps(element, _mm_loadu_ps((float*)(padIn + (x+i) + 56 + (y+j) * padSize_X))), out_matrix15);
					out_matrix16 = _mm_add_ps(_mm_mul_ps(element, _mm_loadu_ps((float*)(padIn + (x+i) + 60 + (y+j) * padSize_X))), out_matrix16);
					out_matrix17 = _mm_add_ps(_mm_mul_ps(element, _mm_loadu_ps((float*)(padIn + (x+i) + 64 + (y+j) * padSize_X))), out_matrix17);
					out_matrix18 = _mm_add_ps(_mm_mul_ps(element, _mm_loadu_ps((float*)(padIn + (x+i) + 68 + (y+j) * padSize_X))), out_matrix18);
					out_matrix19 = _mm_add_ps(_mm_mul_ps(element, _mm_loadu_ps((float*)(padIn + (x+i) + 72 + (y+j) * padSize_X))), out_matrix19);
					out_matrix20 = _mm_add_ps(_mm_mul_ps(element, _mm_loadu_ps((float*)(padIn + (x+i) + 76 + (y+j) * padSize_X))), out_matrix20);
					out_matrix21 = _mm_add_ps(_mm_mul_ps(element, _mm_loadu_ps((float*)(padIn + (x+i) + 80 + (y+j) * padSize_X))), out_matrix21);
					out_matrix22 = _mm_add_ps(_mm_mul_ps(element, _mm_loadu_ps((float*)(padIn + (x+i) + 84 + (y+j) * padSize_X))), out_matrix22);
					out_matrix23 = _mm_add_ps(_mm_mul_ps(element, _mm_loadu_ps((float*)(padIn + (x+i) + 88 + (y+j) * padSize_X))), out_matrix23);
					out_matrix24 = _mm_add_ps(_mm_mul_ps(element, _mm_loadu_ps((float*)(padIn + (x+i) + 92 + (y+j) * padSize_X))), out_matrix24);
					// out_matrix25 = _mm_add_ps(_mm_mul_ps(element, _mm_loadu_ps((float*)(padIn + (x+i) + 96 + (y+j) * padSize_X))), out_matrix25);
					// out_matrix26 = _mm_add_ps(_mm_mul_ps(element, _mm_loadu_ps((float*)(padIn + (x+i) + 100 + (y+j) * padSize_X))), out_matrix26);
					// out_matrix27 = _mm_add_ps(_mm_mul_ps(element, _mm_loadu_ps((float*)(padIn + (x+i) + 104 + (y+j) * padSize_X))), out_matrix27);
					// out_matrix28 = _mm_add_ps(_mm_mul_ps(element, _mm_loadu_ps((float*)(padIn + (x+i) + 108 + (y+j) * padSize_X))), out_matrix28);
					// out_matrix29 = _mm_add_ps(_mm_mul_ps(element, _mm_loadu_ps((float*)(padIn + (x+i) + 112 + (y+j) * padSize_X))), out_matrix29);

				}
			}
			_mm_storeu_ps((float*)(out + x + y * data_size_X), out_matrix1);
			_mm_storeu_ps((float*)(out + x + 4 + y * data_size_X), out_matrix2);
			_mm_storeu_ps((float*)(out + x + 8 + y * data_size_X), out_matrix3);
			_mm_storeu_ps((float*)(out + x + 12 + y * data_size_X), out_matrix4);
			_mm_storeu_ps((float*)(out + x + 16 + y * data_size_X), out_matrix5);
			_mm_storeu_ps((float*)(out + x + 20 + y * data_size_X), out_matrix6);
			_mm_storeu_ps((float*)(out + x + 24 + y * data_size_X), out_matrix7);
			_mm_storeu_ps((float*)(out + x + 28 + y * data_size_X), out_matrix8);
			_mm_storeu_ps((float*)(out + x + 32 + y * data_size_X), out_matrix9);
			_mm_storeu_ps((float*)(out + x + 36 + y * data_size_X), out_matrix10);
			_mm_storeu_ps((float*)(out + x + 40 + y * data_size_X), out_matrix11);
			_mm_storeu_ps((float*)(out + x + 44 + y * data_size_X), out_matrix12);
			_mm_storeu_ps((float*)(out + x + 48 + y * data_size_X), out_matrix13);
			_mm_storeu_ps((float*)(out + x + 52 + y * data_size_X), out_matrix14);
			_mm_storeu_ps((float*)(out + x + 56 + y * data_size_X), out_matrix15);
			_mm_storeu_ps((float*)(out + x + 60 + y * data_size_X), out_matrix16);
			_mm_storeu_ps((float*)(out + x + 64 + y * data_size_X), out_matrix17);
			_mm_storeu_ps((float*)(out + x + 68 + y * data_size_X), out_matrix18);
			_mm_storeu_ps((float*)(out + x + 72 + y * data_size_X), out_matrix19);
			_mm_storeu_ps((float*)(out + x + 76 + y * data_size_X), out_matrix20);
			_mm_storeu_ps((float*)(out + x + 80 + y * data_size_X), out_matrix21);
			_mm_storeu_ps((float*)(out + x + 84 + y * data_size_X), out_matrix22);
			_mm_storeu_ps((float*)(out + x + 88 + y * data_size_X), out_matrix23);
			_mm_storeu_ps((float*)(out + x + 92 + y * data_size_X), out_matrix24);
			// _mm_storeu_ps((float*)(out + x + 96 + y * data_size_X), out_matrix25);
			// _mm_storeu_ps((float*)(out + x + 100 + y * data_size_X), out_matrix26);
			// _mm_storeu_ps((float*)(out + x + 104 + y * data_size_X), out_matrix27);
			// _mm_storeu_ps((float*)(out + x + 108 + y * data_size_X), out_matrix28);
			// _mm_storeu_ps((float*)(out + x + 112 + y * data_size_X), out_matrix29);
		}

		for(int x = data_size_X/96*96; x < data_size_X; x++){
			float temp = out[x+y*data_size_X];
			for(int j = 0; j < kernel_y; j++){
				for(int i = 0; i < kernel_x; i++){
					temp += ker[ i+j * kernel_x] * padIn[(x+i)+(y+j)*padSize_X];
				}
			}
			out[x+y*data_size_X] = temp;
		}
	}

	free(ker);
	free(padIn);
	return 1;
}
