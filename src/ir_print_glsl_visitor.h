/**
 * Based on GLSL optimizer:
 * https://github.com/aras-p/glsl-optimizer 
 */

#ifndef __IR_PRINT_GLSL_VISITOR_H
#define __IR_PRINT_GLSL_VISITOR_H

#include "ir.h"

char *_mesa_print_ir_glsl(void *mem_ctx, struct gl_shader *shader, exec_list *instructions);

#endif /* IR_PRINT_GLSL_VISITOR_H */
