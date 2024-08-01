library verilog;
use verilog.vl_types.all;
entity REGISTER_4BIT is
    port(
        OUTPUT          : out    vl_logic_vector(3 downto 0);
        P_L             : in     vl_logic_vector(3 downto 0);
        LOADN           : in     vl_logic;
        CLOCK           : in     vl_logic;
        INPUT           : in     vl_logic_vector(3 downto 0);
        RESET           : in     vl_logic
    );
end REGISTER_4BIT;
