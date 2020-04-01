#include "header.h"
#define COEF 3
void rotate_basis_y(t_basis *basis, float angle) {
	float prev_x = basis->i->x;
    float prev_z = basis->i->z;
    float deg = angle/(57 * COEF);

    basis->i->x = prev_x * cos(deg) + prev_z * sin(deg);
    basis->i->z = -prev_x * sin(deg) + prev_z * cos(deg);
    
    prev_x = basis->j->x;
    prev_z = basis->j->z;

    basis->j->x = prev_x * cos(deg) + prev_z * sin(deg);
    basis->j->z = -prev_x * sin(deg) + prev_z * cos(deg);
    
    prev_x = basis->k->x;
    prev_z = basis->k->z;
    
    basis->k->x = prev_x * cos(deg) + prev_z * sin(deg);
    basis->k->z = -prev_x * sin(deg) + prev_z * cos(deg);
}

void rotate_basis_z(t_basis *basis, float angle) {
    float prev_x = basis->i->x;
    float prev_y = basis->i->y;
    float deg = angle/(57 * COEF);

    basis->i->x = prev_x * cos(deg) - prev_y * sin(deg);
    basis->i->y = prev_x * sin(deg) + prev_y * cos(deg);
    
    prev_x = basis->j->x;
    prev_y = basis->j->y;
    
    basis->j->x = prev_x * cos(deg) - prev_y * sin(deg);
    basis->j->y = prev_x * sin(deg) + prev_y * cos(deg);

    prev_x = basis->k->x;
    prev_y = basis->k->y;
    
    basis->k->x = prev_x * cos(deg) - prev_y * sin(deg);
    basis->k->y = prev_x * sin(deg) + prev_y * cos(deg);
}

void rotate_basis_x(t_basis *basis, float angle) {
    float prev_z = basis->i->z;
    float prev_y = basis->i->y;
    float deg = angle/(57 * COEF);

    basis->i->y = -prev_z * sin(deg) + prev_y * cos(deg);
    basis->i->z = prev_z * cos(deg) + prev_y * sin(deg);

    prev_z = basis->j->z;
    prev_y = basis->j->y;

    basis->j->y = -prev_z * sin(deg) + prev_y * cos(deg);
    basis->j->z = prev_z * cos(deg) + prev_y * sin(deg);

    prev_z = basis->k->z;
    prev_y = basis->k->y;
    
    basis->k->y = -prev_z * sin(deg) + prev_y * cos(deg);
    basis->k->z = prev_z * cos(deg) + prev_y * sin(deg);
}

void update_basis(t_basis *basis) {
    rotate_basis_x(basis, 1);
    // prev_x = basis->j->x;
    // prev_y = basis->j->y;

    // basis->j->x = prev_x * cos(1/57) - prev_y * sin(1/57);
    // basis->j->y = prev_x * sin(1/57) + prev_y * cos(1/57);
}