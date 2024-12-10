import { PartialType } from '@nestjs/mapped-types';
import { CreateStrategyDto } from './create-strategy.dto';
import { IsNumber, IsOptional, IsPositive, Min } from 'class-validator';
import { Type } from 'class-transformer';

export class UpdateStrategyDto extends PartialType(CreateStrategyDto) {
@IsOptional()
  @IsNumber()
  @IsPositive()
  userId?: number;

  @IsOptional()
  @IsNumber()
  @Type(() => Number)
  @Min(0)
  totalIncome?: number;

  @IsOptional()
  @IsNumber()
  @Type(() => Number)
  @Min(0)
  foodAllocation?: number;

  @IsOptional()
  @IsNumber()
  @Type(() => Number)
  @Min(0)
  rentAllocation?: number;

  @IsOptional()
  @IsNumber()
  @Type(() => Number)
  @Min(0)
  billsAllocation?: number;

  @IsOptional()
  @IsNumber()
  @Type(() => Number)
  @Min(0)
  otherAllocation?: number;
}
