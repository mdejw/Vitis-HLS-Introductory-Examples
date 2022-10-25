/*
 * Copyright 2022 Xilinx, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "example.h"

int main() {

  int i, retval = 0;
  const char N = 10;
  char a, b, c;
  ofstream FILE;

  // Save the results to a file
  FILE.open ("result.dat");
  
  for (i = 0; i < N; ++i) {
    // Call the function
    top(i, i, i, &a, &b, &c);
    FILE << (int)a << " " << (int)b << " " << (int)c << endl;
    cout << (int)a << " " << (int)b << " " << (int)c << endl; 
  }
  
  FILE.close();
  
  // Compare the results file with the golden results
  retval = system("diff --brief -w result.dat result.golden.dat");
  if (retval != 0) {
    printf("Test failed  !!!\n");
    retval = 1;
  } else {
    printf("Test passed !\n");
  }
  
  // Return 0 if the test passed
  return retval;
}

