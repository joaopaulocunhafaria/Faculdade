library verilog;
use verilog.vl_types.all;
entity ULA_32bit is
    port(
        COUT            : out    vl_logic;
        INVA            : in     vl_logic;
        ENA             : in     vl_logic;
        ENB             : in     vl_logic;
        CIN             : in     vl_logic;
        F0              : in     vl_logic;
        F1              : in     vl_logic;
        A               : in     vl_logic_vector(31 downto 0);
        B               : in     vl_logic_vector(31 downto 0);
        OUTPUT          : out    vl_logic_vector(31 downto 0)
    );
end ULA_32bit;
