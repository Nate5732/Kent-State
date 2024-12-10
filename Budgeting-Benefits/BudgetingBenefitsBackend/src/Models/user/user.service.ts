import { Injectable } from '@nestjs/common';
import { InjectRepository } from '@nestjs/typeorm';
import { Repository } from 'typeorm';
import { CreateUserDto } from './dto/create-user.dto';
import { User } from './entities/user.entity';
import { UpdateUserDto } from './dto/update-user.dto';
import * as bcrypt from 'bcrypt'

@Injectable()
export class UserService {
  constructor(
    @InjectRepository(User)
    private readonly userRepository: Repository<User>,
  ) {}

  async create(createUserDto: CreateUserDto): Promise<User> {
    const user = new User();
    console.log(createUserDto.name)
    console.log(createUserDto.email)
    console.log(createUserDto.password)
    user.name = createUserDto.name;
    user.email = createUserDto.email;
    const salt = await bcrypt.genSalt(10);
    const hashedPassword = await bcrypt.hash(createUserDto.password, salt);
    user.password = hashedPassword;
  
    try {
      return await this.userRepository.save(user);
    } catch (error) {
      console.error(error);
      throw error;
    }
  }

  findAll() {
    return `This action returns all user`;
  }

  async findOneEmail(email: string) {
    let user = await this.userRepository.findOne({ where: { email } });

    if(!user) {
      throw Error("No user found");
    } else {
      return user;
    }
  }

  async findOneId(id: number) {
    let user = await this.userRepository.findOne({ where: { id } });

    if(!user) {
      throw Error("No user found");
    } else {
      return user;
    }
  }

  async update(id: number, updateUserDto: UpdateUserDto) {
    await this.userRepository.update(id, updateUserDto);
    return this.findOneId(id);
}

  remove(id: number) {
    return `This action removes a #${id} user`;
  }
}
