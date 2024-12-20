library verilog;
use verilog.vl_types.all;
entity REGISTER32bit_vlg_sample_tst is
    port(
        CLOCK           : in     vl_logic;
        IN_C            : in     vl_logic_vector(31 downto 0);
        IN_LOAD         : in     vl_logic_vector(31 downto 0);
        IN_MEM          : in     vl_logic_vector(31 downto 0);
        IN_SELECT       : in     vl_logic;
        LOAD            : in     vl_logic;
        OUT_EN          : in     vl_logic;
        OUT_MEM_EN      : in     vl_logic;
        WRITE_EN        : in     vl_logic;
        sampler_tx      : out    vl_logic
    );
end REGISTER32bit_vlg_sample_tst;
