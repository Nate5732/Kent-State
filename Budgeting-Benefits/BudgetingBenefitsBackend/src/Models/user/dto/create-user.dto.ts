import { IsEmail, MinLength, MaxLength, IsInt, IsOptional } from 'class-validator';

export class CreateUserDto {
  @IsEmail()
  email: string;

  @MinLength(8)
  @MaxLength(128)
  password: string;

  name: string;

  @IsOptional()
  @IsInt()
  monthlyInc?: number = 0;
  
  @IsOptional()
  emgfund?: number = 0;

  @IsOptional()
  savings?: number = 0;

  @IsOptional()
  debt?: number = 0;
}