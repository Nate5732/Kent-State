import { IsEmail, IsInt, IsOptional } from 'class-validator';

export class UpdateUserDto {
  @IsEmail()
  email?: string;

  name?: string;

  @IsOptional()
  @IsInt()
  monthlyInc?: number;

  @IsOptional()
  emgfund?: number;

  @IsOptional()
  savings?: number;

  @IsOptional()
  debt?: number;
}