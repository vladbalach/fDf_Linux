#include "header.h"

static void swap_float(float *a, float *b) {
    float tmp = *a;
    *a = *b;
    *b = tmp;
}

t_vector *v_mult(t_vector *vector, float scalar) {
	t_vector *new = malloc(sizeof(t_vector));
	new->x = vector->x * scalar;
	new->y = vector->y * scalar;
	new->z = vector->z * scalar;
	return new;
}

t_vector *v_add_v(t_vector *v1, t_vector *v2) {
	t_vector *new = malloc(sizeof(t_vector));
	new->x = v1->x + v2->x;
	new->y = v1->y + v2->y;
	new->z = v1->z + v2->z;
	return new;
}

void draw_line(t_vector *v1, t_vector *v2, t_basis *basis, int w, int h ,Uint32 color ,Uint32* pixels, t_camera *camera) {

	if (v1->z == v2->z) {
		if (v1->z * 4 < 255)
		color |= (int)(v1->z * 4);
		unsigned int g = (color >> 8) & 255;
		printf("g = %d\n",g);
		g -= (unsigned int)((int)v1->z * 4);
		color &= 4294902015;
		color |= (g << 8);
	}
	t_vector *v_x = v_mult(basis->i, v1->x);
	t_vector *v_y = v_mult(basis->j, v1->y);
	t_vector *v_z = v_mult(basis->k, v1->z);

	t_vector *p1 = v_add_v(v_x, v_y);
	p1 = v_add_v(p1, v_z);

	v_x = v_mult(basis->i, v2->x);
	v_y = v_mult(basis->j, v2->y);
	v_z = v_mult(basis->k, v2->z);

	t_vector *p2 = v_add_v(v_x, v_y);
	p2 = v_add_v(p2, v_z);

	float x1 = p1->x + camera->x;
	float x2 = p2->x + camera->x;
	float y1 = p1->y + camera->y;
	float y2 = p2->y + camera->y;

	float x, y;
	if ((x1 - x2) * (x1 - x2) > (y1 - y2) * (y1 - y2)) {
		// if x1 > x2 then swap A1 and A2
		if (x1 > x2) {
			swap_float(&x1, &x2);
			swap_float(&y1, &y2);
		}
		for (x = x1; x < x2; x += 1) {
			y = ((y2 - y1) / (x2 - x1)) * (x - x1) + y1;
			if ((x > 0) && (x < w) && (y > 0) && (y < h))
				* (pixels + (int)y * w + (int)x) = color;
		}
	}
	else {
		// if y1 > y2 then swap A1 and A2
		if (y1 > y2) {
			swap_float(&x1, &x2);
			swap_float(&y1, &y2);
		}
		for (y = y1; y < y2; y += 1) {

			x = ((x2 - x1) / (y2 - y1)) * (y - y1) + x1;
			if ((x > 0) && (x < w) && (y > 0) && (y < h))
				* (pixels + (int)y * w + (int)x) = color;
		}
	}
}