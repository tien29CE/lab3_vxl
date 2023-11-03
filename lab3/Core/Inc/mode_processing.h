/*
 * mode_processing.h
 *
 *  Created on: Oct 17, 2023
 *      Author: Admin
 */

#ifndef INC_MODE_PROCESSING_H_
#define INC_MODE_PROCESSING_H_

enum NO_OF_MODES {Normal_mode, Modify_red, Modify_yellow, Modify_green};
extern enum NO_OF_MODES mode;

void mode_processing(void);

void modify_red(void);
void modify_yellow(void);
void modufy_green(void);


#endif /* INC_MODE_PROCESSING_H_ */
