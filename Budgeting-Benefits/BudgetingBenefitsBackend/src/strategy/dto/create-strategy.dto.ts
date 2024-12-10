import { Type } from "class-transformer";
import { IsNumber, IsPositive, Min } from "class-validator";

export class CreateStrategyDto {
    @IsNumber()
    @IsPositive()
    userId: number;
  
    @IsNumber()
    @Type(() => Number)
    @Min(0)
    totalIncome: number;
  
    @IsNumber()
    @Type(() => Number)
    @Min(0)
    foodAllocation: number;
  
    @IsNumber()
    @Type(() => Number)
    @Min(0)
    rentAllocation: number;
  
    @IsNumber()
    @Type(() => Number)
    @Min(0)
    billsAllocation: number;
  
    @IsNumber()
    @Type(() => Number)
    @Min(0)
    otherAllocation: number;
}

