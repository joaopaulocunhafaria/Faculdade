library verilog;
use verilog.vl_types.all;
entity REGISTER_4BIT_vlg_sample_tst is
    port(
        CLOCK           : in     vl_logic;
        INPUT           : in     vl_logic_vector(3 downto 0);
        LOADN           : in     vl_logic;
        P_L             : in     vl_logic_vector(3 downto 0);
        RESET           : in     vl_logic;
        sampler_tx      : out    vl_logic
    );
end REGISTER_4BIT_vlg_sample_tst;
