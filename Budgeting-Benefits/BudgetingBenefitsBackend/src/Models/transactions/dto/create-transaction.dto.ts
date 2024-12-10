import { IsNumber, IsString, IsDate, IsPositive } from 'class-validator';
import { Type } from 'class-transformer';

export class CreateTransactionDto {
  @IsNumber()
  userId: number;

  @IsString()
  category: string;

  @IsDate()
  @Type(() => Date)
  date: Date;

  @IsNumber()
  @IsPositive()
  amount: number;
}