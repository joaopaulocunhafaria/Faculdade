library verilog;
use verilog.vl_types.all;
entity FULL_ADDER_1BIT is
    port(
        S               : out    vl_logic;
        CIN             : in     vl_logic;
        A               : in     vl_logic;
        B               : in     vl_logic;
        ENA             : in     vl_logic;
        COUT            : out    vl_logic
    );
end FULL_ADDER_1BIT;
