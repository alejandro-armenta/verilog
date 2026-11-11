module arbiter (

    clk,
    rstb,

    request0,
    request1,
    request2,
    request3,

    end_transaction0,
    end_transaction1,
    end_transaction2,
    end_transaction3,

    grant0,
    grant1,
    grant2,
    grant3

);

  input clk;
  input rstb;

  input request0;
  input request1;
  input request2;
  input request3;

  input end_transaction0;
  input end_transaction1;
  input end_transaction2;
  input end_transaction3;

  output grant0;
  output grant1;
  output grant2;
  output grant3;

  // these are not passed to other modules are local to this module
  localparam IDLE = 3'd0, GRANT0 = 3'd1, GRANT1 = 3'd2, GRANT2 = 3'd3, GRANT3 = 3'd4;

  // esto te lo dice en forma de estado
  reg [2:0] arb_state, arb_state_next;

  // este te dice a quien se le dio el grant
  reg [3:0] grant, grant_next;

  reg [3:0] serv_hist, serv_hist_next;

  wire grant0, grant1, grant2, grant3;

  // aqui hay una distribucion de los bits
  assign {grant3, grant2, grant1, grant0} = grant;

  // sequencial

  always @(posedge clk or negedge rstb) begin

    if (!rstb) begin

      arb_state <= IDLE;

      grant <= 'd0;

      // aqui es 8
      serv_hist <= 4'b1000;

    end else begin

      arb_state <= arb_state_next;

      grant <= grant_next;

      serv_hist <= serv_hist_next;

    end

  end

  // combinacional
  always @(*) begin

    arb_state_next = arb_state;

    grant_next = grant;

    serv_hist_next = serv_hist;

    case (arb_state)

      // sistema round robin
      // solo en el idle utiliza la historia
      IDLE: begin

        case (1'b1)

          serv_hist[3]: begin

            if (request0) begin

              arb_state_next = GRANT0;
              grant_next = 4'b0001;

            end else if (request1) begin

              arb_state_next = GRANT1;
              grant_next = 4'b0010;

            end else if (request2) begin

              arb_state_next = GRANT2;
              grant_next = 4'b0100;

            end else if (request3) begin

              arb_state_next = GRANT3;
              grant_next = 4'b1000;

            end


          end

          serv_hist[2]: begin

            if (request3) begin

              arb_state_next = GRANT3;
              grant_next = 4'b1000;

            end else if (request0) begin

              arb_state_next = GRANT0;
              grant_next = 4'b0001;

            end else if (request1) begin

              arb_state_next = GRANT1;
              grant_next = 4'b0010;

            end else if (request2) begin

              arb_state_next = GRANT2;
              grant_next = 4'b0100;

            end


          end

          serv_hist[1]: begin

            if (request2) begin

              arb_state_next = GRANT2;
              grant_next = 4'b0100;

            end else if (request3) begin

              arb_state_next = GRANT3;
              grant_next = 4'b1000;

            end else if (request0) begin

              arb_state_next = GRANT0;
              grant_next = 4'b0001;

            end else if (request1) begin

              arb_state_next = GRANT1;
              grant_next = 4'b0010;

            end


          end

          serv_hist[0]: begin

            if (request1) begin

              arb_state_next = GRANT1;
              grant_next = 4'b0010;

            end else if (request2) begin

              arb_state_next = GRANT2;
              grant_next = 4'b0100;

            end else if (request3) begin

              arb_state_next = GRANT3;
              grant_next = 4'b1000;

            end else if (request0) begin

              arb_state_next = GRANT0;
              grant_next = 4'b0001;

            end

          end

          default: begin
          end

        endcase

      end

      GRANT0: begin
        // es combinacional 

        if (end_transaction0) begin

          arb_state_next = IDLE;
          grant_next     = 'd0;  // no hay nadie
          serv_hist_next = 4'b0001;

        end


      end

      GRANT1: begin

        if (end_transaction1) begin

          arb_state_next = IDLE;
          grant_next     = 'd0;  // no hay nadie
          serv_hist_next = 4'b0010;

        end

      end

      GRANT2: begin
        if (end_transaction2) begin

          arb_state_next = IDLE;
          grant_next     = 'd0;  // no hay nadie
          serv_hist_next = 4'b0100;

        end

      end

      GRANT3: begin
        if (end_transaction3) begin

          arb_state_next = IDLE;
          grant_next     = 'd0;  // no hay nadie
          serv_hist_next = 4'b1000;

        end

      end

      default: begin
      end

    endcase

  end

endmodule

