struct mult_div_values {
    int mult;
    float div;
};

bool is_valid_dimensions (char *, char *); //done
mult_div_values** create_table (int, int);
void print_table (mult_div_values**, int, int);
void set_mult_values(mult_div_values **, int, int);
void set_div_values(mult_div_values **, int, int);
void delete_table(mult_div_values **, int, int);
int re_prompt (int &, int &);